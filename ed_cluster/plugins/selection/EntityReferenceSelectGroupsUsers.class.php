<?php

class EntityReferenceSelectGroupsUsers extends EntityReference_SelectionHandler_Generic {

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

    if (class_exists($class_name = 'EntityReferenceSelectGroupsUsers_' . $target_entity_type)) {
      return new $class_name($field, $instance, $entity_type, $entity);
    }
    else {
      return new EntityReferenceSelectGroupsUsers($field, $instance, $entity_type, $entity);
    }
  }
  
  /**
   * Override that would serve user fullname or fall back to default.
   */
  public function getLabel($entity) {
    if (isset($entity->ed_field_full_name[LANGUAGE_NONE][0]['value'])) {
      return $entity->ed_field_full_name['und'][0]['value'];
    }

    return parent::getLabel($entity);
  }
}

class EntityReferenceSelectGroupsUsers_user extends EntityReferenceSelectGroupsUsers {
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

    // Only active users are allowed
    $query->propertyCondition('status', 1);

    // Get selected group identifiers
    if (!empty($this->entity->og_group_ref[LANGUAGE_NONE])) {
      $groups = array_map(function ($element) { return $element['target_id']; }, $this->entity->og_group_ref[LANGUAGE_NONE]);
    } else if (isset($this->entity)) {
      $field = field_info_field('og_group_ref');
      $instance = field_info_instance('node', 'og_group_ref', $this->entity->type);

      if ($field && $instance && module_exists('entityreference_prepopulate') || empty($instance['settings']['behaviors']['prepopulate'])) {
          $groups = entityreference_prepopulate_get_values($field, $instance, FALSE);
      }
    }

    // Add condition to only select group members
    if (!empty($groups)) {
      $uids = db_select('og_membership', 'ogm')
        ->distinct()
        ->fields('ogm', array('etid'))
        ->condition('ogm.entity_type', 'user')
        ->condition('ogm.group_type', 'node')
        ->condition('ogm.gid', $groups, 'IN')
        ->condition('ogm.state', OG_STATE_ACTIVE)
        ->execute()
        ->fetchCol();
      $query->propertyCondition('uid', $uids, 'IN');
    } else {
        // This will keep the field empty if no groups are selected
      $query->propertyCondition('uid', -1);
    }

    return $query;
  }
}

