<?php

class EntityReferenceSelectFullName extends EntityReference_SelectionHandler_Generic {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    $target_entity_type = $field['settings']['target_type'];

    // Check if the entity type does exist and has a base table.
    $entity_info = entity_get_info($target_entity_type);
    if (empty($entity_info['base table'])) {
      return EntityReference_SelectionHandler_Broken::getInstance($field, $instance);
    }

    if (class_exists($class_name = 'EntityReferenceSelectFullName_' . $target_entity_type)) {
      return new $class_name($field, $instance, $entity_type, $entity);
    }
    else {
      return new EntityReferenceSelectFullName($field, $instance, $entity_type, $entity);
    }
  }
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $options = array();
    $entity_type = $this->field['settings']['target_type'];
    $query = $this->buildEntityFieldQuery($match, $match_operator);
    if ($limit > 0) {
      $query->range(0, $limit);
    }

    $results = $query->execute();

    if (!empty($results[$entity_type])) {
      $entities = entity_load($entity_type, array_keys($results[$entity_type]));
      foreach ($entities as $entity_id => $entity) {
        list(,, $bundle) = entity_extract_ids($entity_type, $entity);
        //$options[$bundle][$entity_id] = check_plain($this->getLabel($entity));
		$options[$bundle][$entity_id] = $this->getFullName($entity);
      }
    }

    return $options;
  }

  public function getFullName($entity) {
    if (isset($entity->ed_field_full_name[LANGUAGE_NONE][0]['value'])) {
      return $entity->ed_field_full_name['und'][0]['value'];
    }
    return $entity->name;
  }

  protected function __construct($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    $this->field = $field;
    $this->instance = $instance;
    $this->entity_type = $entity_type;
    $this->entity = $entity;
  }
}

class EntityReferenceSelectFullName_user extends EntityReferenceSelectFullName {
  public function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {
    $query = parent::buildEntityFieldQuery($match, $match_operator);

    // The user entity doesn't have a label column.
    if (isset($match)) {
      //This line uses the regular username:
      //$query->propertyCondition('name', $match, $match_operator);

      //This was added to use the "realname" field instead of the regular username:
      //CHANGE THIS:
      $query->fieldCondition('ed_field_full_name', 'value', $match, $match_operator);
    }

    // Adding the 'user_access' tag is sadly insufficient for users: core
    // requires us to also know about the concept of 'blocked' and
    // 'active'.
    if (!user_access('administer users')) {
      $query->propertyCondition('status', 1);
    }
    return $query;
  }

  public function entityFieldQueryAlter(SelectQueryInterface $query) {
    if (user_access('administer users')) {
      // In addition, if the user is administrator, we need to make sure to
      // match the anonymous user, that doesn't actually have a name in the
      // database.
      $conditions = &$query->conditions();
      foreach ($conditions as $key => $condition) {
        if ($key !== '#conjunction' && is_string($condition['field']) && $condition['field'] === 'users.mail') {
          // Remove the condition.
          unset($conditions[$key]);

          // Re-add the condition and a condition on uid = 0 so that we end up
          // with a query in the form:
          //    WHERE (name LIKE :name) OR (:anonymous_name LIKE :name AND uid = 0)
          $or = db_or();
          $or->condition($condition['field'], $condition['value'], $condition['operator']);
          // Sadly, the Database layer doesn't allow us to build a condition
          // in the form ':placeholder = :placeholder2', because the 'field'
          // part of a condition is always escaped.
          // As a (cheap) workaround, we separately build a condition with no
          // field, and concatenate the field and the condition separately.
          $value_part = db_and();
          $value_part->condition('anonymous_name', $condition['value'], $condition['operator']);
          $value_part->compile(Database::getConnection(), $query);
          $or->condition(db_and()
              ->where(str_replace('anonymous_name', ':anonymous_name', (string) $value_part), $value_part->arguments() + array(':anonymous_name' => format_username(user_load(0))))
              ->condition('users.uid', 0)
          );

          $query->condition($or);

        }
      }
    }
  }
}
