<?php


//	og role getter
function edf_get_og_roles() {
	static $roles;
	if ($roles) return $roles;

	$q = db_select('og_role', 'ogr');
	$q->fields('ogr', ['rid', 'name']);
	$role_datas = $q->execute()->fetchAll(PDO::FETCH_ASSOC);
	$roles = [];
	foreach ($role_datas as $role_data) {
		$roles[$role_data['rid']] = $role_data['name']; 
	}

	return $roles;
}

//	role getter
function edf_get_roles() {
	static $roles;
	if ($roles) return $roles;

	$q = db_select('role', 'r');
	$q->fields('r', ['rid', 'name']);
	$role_datas = $q->execute()->fetchAll(PDO::FETCH_ASSOC);
	$roles = [];
	foreach ($role_datas as $role_data) {
		$roles[$role_data['rid']] = $role_data['name']; 
	}

	return $roles;
}

//	universal user getter
//	supported fields:
//	'full_name', groups', 'study_groups', 'roles'
//	supported filters
//	'uid', 'gid', 'max_offline_time'
//	usage example: edf_get_users(['full_name'], ['gid' => 10]);
function edf_get_users($fields = ['groups', 'full_name', 'study_groups', 'roles'], $filter = []) {
	
	//	get raw users from db	
	$q = db_select('users', 'u'); 
	$q->condition('u.status', 1); 
	$q->fields('u', ['uid', 'data']);

	//	filter by login 
	if (isset($filter['max_offline_time'])) {
		$q->condition('u.login', time() - $filter['max_offline_time'], '>');
	}

	//	filter by uid
	if (isset($filter['uid'])) {
		$q->condition('u.uid', $filter['uid']);
	}

	//	optionally full name
	if (in_array('full_name', $fields)) {
		$q->leftJoin('field_data_ed_field_full_name', 'fn', 'fn.entity_id = u.uid');
		$q->addField('fn', 'ed_field_full_name_value', 'full_name');
	}

	//	optionally groups or gid filter
	if (isset($filters['gid']) || in_array('groups', $fields)) {
		$q->leftJoin('og_membership', 'ogm', 'ogm.etid = u.uid AND ogm.entity_type = \'user\' AND ogm.state = 1');
	}

	//	filter by gid
	if (isset($filter['gid'])) {
		$q->condition('ogm.gid', $filter['gid']);
	}

	//	optionally groups
	if (in_array('groups', $fields)) {
		$q->addField('ogm', 'gid', 'group_id');

		$q->leftJoin('node', 'n', 'n.nid = ogm.gid AND n.type = \'ed_cluster\' AND n.uid = u.uid');
		$q->addField('n', 'nid', 'created_group_id');

		$q->leftJoin('og_users_roles', 'ogur', 'ogur.uid = u.uid');
		$q->addField('ogur', 'gid', 'group_role_group_id');
		$q->addField('ogur', 'rid', 'group_role_id');
	}

	//	optionally study groups
	if (in_array('study_groups', $fields)) {
		$q->leftJoin('field_data_ed_field_study_group', 'sg', 'sg.entity_id = u.uid');
		$q->addField('sg', 'ed_field_study_group_value', 'study_group_id');
	}

	//	optionally roles
	if (in_array('roles', $fields)) {
		$q->leftJoin('users_roles', 'ur', 'ur.uid = u.uid');
  		$q->addField('ur', 'rid', 'role_id');
	}



	//	exec
	$raw_users = $q->execute()->fetchAll(PDO::FETCH_ASSOC);
	unset($q);

	//	convert to users
	$users = [];

	foreach ($raw_users as $raw_user) {
		//	create new user items
		if (!isset($users[$raw_user['uid']])) {
			$new_user = [ 'uid' => $raw_user['uid'] ];

			if (in_array('groups', $fields)) {
				$new_user['groups'] = [];
			}

			if (in_array('study_groups', $fields)) {
				$new_user['study_groups'] = [];
			}

			if (in_array('roles', $fields)) {
				$new_user['roles'] = [];
			}

			if (in_array('full_name', $fields)) {
				//	try to get full name from data
				$data = unserialize($raw_user['data']);
				if (isset($data['hybridauth'])) {
					if (isset($data['hybridauth']['displayName'])) {
						$new_user['full_name'] = $data['hybridauth']['displayName'];
					}
				}

				//	try to get full name from joined table
				if (isset($raw_user['full_name'])) {
					$new_user['full_name'] = $raw_user['full_name'];
				}
			}

			$users[$raw_user['uid']] = $new_user;
		}

		//	fill user item
		$user =& $users[$raw_user['uid']];

		//	groups
		if (in_array('groups', $fields)) {

			if (!is_null($raw_user['group_id'])) {
				//	create new group items
				if (!isset($user['groups'][$raw_user['group_id']])) {
					$user['groups'][$raw_user['group_id']] = [
						'roles' => [],
						'creator' => false,
						'admin' => false,
						'group_id' => $raw_user['group_id']
					];
				}
			}

			//	fill group items
			if (!is_null($raw_user['created_group_id'])) {
				if (isset($user['groups'][$raw_user['created_group_id']])) {
					$user['groups'][$raw_user['created_group_id']]['creator'] = true;
					$user['groups'][$raw_user['created_group_id']]['admin'] = true;
				}
			}

			if (!is_null($raw_user['group_role_group_id'])) {
				if (isset($user['groups'][$raw_user['group_role_group_id']])) {
					$role = edf_get_og_roles()[$raw_user['group_role_id']];
					if (!in_array($role, $user['groups'][$raw_user['group_role_group_id']]['roles'])) {
					$user['groups'][$raw_user['group_role_group_id']]['roles'] []= $role;
						if ($role == OG_ADMINISTRATOR_ROLE) {
							$user['groups'][$raw_user['group_role_group_id']]['admin'] = true;
						}
					}
				}
			}

			if (!is_null($raw_user['study_group_id'])) {
				if(!in_array($raw_user['study_group_id'], $user['study_groups'])) {
					$user['study_groups'] []= $raw_user['study_group_id'];
				}
			}

			if (!is_null($raw_user['role_id'])) {
				$role = edf_get_roles()[$raw_user['role_id']];
				if (!in_array($role, $user['roles'])) {
					$user['roles'] []= $role;
				}
			}
		}

		unset($user);
	}

	return $users;
}

//	helper function to separate og admins from other users
//	if used without gid specified, returns array of occurring groups, each containing admin users
//	if used with gid, returns array of admin users for that group only and removes the admins from user array
function edf_extract_og_admins(&$users, $extract_gid = -1) {
	$admins = [];
	foreach ($users as $uid => &$user) {
		foreach ($user['groups'] as $gid => $group) {
			if ($group['admin']) {
				if (!isset($admins[$gid])) {
					$admins[$gid] = [];
				}
				$admins[$gid][$user['uid']] =& $user;
			}
		}
		unset($user);
	}

	if ($extract_gid != -1) {
		$admins = $admins[$extract_gid];
		foreach ($admins as $admin) {
			unset($users[$admin['uid']]);
		}
	}

	return $admins;
}

//	universal task getter
//	supported fields:
//	'due_date', 'study_groups', 'targeted_users', 'answers_by_uid'
//	supported filters (EQ only)
//	'gid', 'task_id', 'max_time_ago_changed'
//	usage example: edf_get_tasks(['due_date'], ['uid' => 5, 'gid' => 3])
function edf_get_tasks($fields = ['due_date', 'study_groups', 'targeted_users', 'answers_by_uid'], $filter = []) {

	//	get raw tasks from db
	$q = db_select('node', 'n');
	$q->condition('n.type', 'ed_task');
	$q->condition('n.status', 1);
	$q->addField('n', 'nid', 'task_id');
	$q->addField('n', 'title', 'title');

	$q->join('og_membership', 'ogm', 'ogm.etid = n.nid');
	$q->addField('ogm', 'gid', 'gid');

	//	changed time ago filter 
	if (isset($filter['max_time_ago_changed'])) {
		$q->condition('n.changed', time() - $filter['max_time_ago_changed'], '>');
	}

	//	gid filter
	if (isset($filter['gid'])) {
		$q->condition('ogm.gid', $filters['gid']);
	}

	//	task_id filter
	if (isset($filter['task_id'])) {
		$q->condition('n.nid', $filters['task_id']);
	}

	//	changed filter
	if (isset($filter['changed'])) {
		$q->condition('n.changed', $filters['changed']);
	}

	//  optionally due date
	if (in_array('due_date', $fields)) {
		$q->join('field_data_ed_task_due_date', 'dd', 'dd.entity_id = n.nid');
		$q->addField('dd', 'ed_task_due_date_value', 'due_date');
	}

	//  optionally study groups
	if (in_array('study_groups', $fields)) {
		$q->leftJoin('field_data_ed_task_field_study_group', 'sg', 'sg.entity_id = n.nid');
		$q->addField('sg', 'ed_task_field_study_group_value', 'study_group_id');
	}

	//  optionally targeted users
	if (in_array('targeted_users', $fields)) {
		$q->leftJoin('field_data_ed_field_to_group_member', 'tm', 'tm.entity_id = n.nid');
		$q->addField('tm', 'ed_field_to_group_member_target_id', 'targeted_user_id');
	}

	//	optionally answers
	if (in_array('answers_by_uid', $fields)) {
		$q->leftJoin('field_data_field_ref_to_task', 'rt', 'rt.field_ref_to_task_target_id = n.nid');
		$q->addField('rt', 'entity_id', 'answer_id');

		$q->leftJoin('node', 'n2', 'n2.nid = rt.entity_id');
		$q->addField('n2', 'uid', 'answer_uid');
		$q->addField('n2', 'created', 'answer_created');
		$q->addField('n2', 'changed', 'answer_changed');

		$q->leftJoin('comment', 'c', 'c.nid = rt.entity_id');
		$q->addField('c', 'created', 'grade_created');
		$q->addField('c', 'uid', 'grade_uid');
		$q->addField('c', 'cid', 'grade_id');

		$q->leftJoin('field_data_ed_answer_grade', 'fg', 'fg.entity_id = c.cid');
		$q->addField('fg', 'ed_answer_grade_value', 'grade_grade');

		$q->leftJoin('field_data_ed_answer_status', 'fs', 'fs.entity_id = c.cid');
		$q->addField('fs', 'ed_answer_status_value', 'grade_status');
	}

	//  exec
	$raw_tasks = $q->execute()->fetchAll(PDO::FETCH_ASSOC);
	unset($q);

	//	convert to tasks
	$tasks = [];

	foreach ($raw_tasks as $raw_task) {
		//	create new task items
		if (!isset($tasks[$raw_task['task_id']])) {
			$new_task = [ 
				'task_id' => $raw_task['task_id'],
				'title' => $raw_task['title'],
				'gid' => $raw_task['gid']
			];

			if (in_array('due_date', $fields)) {
				$new_task['due_date'] = $raw_task['due_date'];
			}

			if (in_array('study_groups', $fields)) {
				$new_task['study_groups'] = [];
			}

			if (in_array('targeted_users', $fields)) {
				$new_task['targeted_users'] = [];
			}

			if (in_array('answers_by_uid', $fields)) {
				$new_task['answers_by_uid'] = [];
			}

			$tasks[$raw_task['task_id']] = $new_task;
		}

		//	fill task items
		$task =& $tasks[$raw_task['task_id']];

		if (!is_null($raw_task['study_group_id'])) {
			if (!in_array($raw_task['study_group_id'], $task['study_groups'])) {
				$task['study_groups'] []= $raw_task['study_group_id'];
			}
		}

		if (!is_null($raw_task['targeted_user_id'])) {
			if (!in_array($raw_task['targeted_user_id'], $task['targeted_users'])) {
				$task['targeted_users'] []= $raw_task['targeted_user_id'];
			}
		}

		if (!is_null($raw_task['answer_id'])) {
			//	answer item creation
			if (!isset($task['answers_by_uid'][$raw_task['answer_uid']])) {
				$new_answer = [
					'id' => $raw_task['answer_id'],
					'uid' => $raw_task['answer_uid'],
					'created' => $raw_task['answer_created'],
					'changed' => $raw_task['answer_changed'],
					'grades' => []
				];
				$task['answers_by_uid'][$raw_task['answer_uid']] = $new_answer;
			}

			//	grade item creation
			if (!is_null($raw_task['grade_id'])) {
				if (!isset($task['answers'][$raw_task['answer_uid']]['grades'][$raw_task['grade_id']])) {
					$new_grade = [
						'id' => $raw_task['grade_id'],
						'uid' => $raw_task['grade_uid'],
						'created' => $raw_task['grade_created'],
						'grade' => $raw_task['grade_grade'],
						'status' => $raw_task['grade_status']
					];
					$task['answers_by_uid'][$raw_task['answer_uid']]['grades'][$raw_task['grade_id']] = $new_grade;
				}
			}

		}

		unset($task);
	}

	return $tasks;
}

//	helper function to transfer user relevant task data to users
function edf_fill_user_tasks(&$users, $tasks) {
	//	sort tasks by gid
	$tasks_by_gid = [];
	foreach ($tasks as &$task) {
		if (!isset($tasks_by_gid[$task['gid']])) {
			$tasks_by_gid[$task['gid']] = [];
		}
		$tasks_by_gid[$task['gid']] []=& $task;
		unset($task);
	}

	$admins = edf_extract_og_admins($users);

	//	copy relevant task parts to users
	foreach ($users as &$user) {
		foreach ($user['groups'] as &$group) {
			if ($group['admin']) continue;

			$group['tasks'] = [];
			if (isset($tasks_by_gid[$group['group_id']])) {
				foreach ($tasks_by_gid[$group['group_id']] as $task) {

					//	check if applicable
					if (count($task['study_groups']) > 0) {
						$applicable = false;

						foreach ($task['study_groups'] as $study_group) {
							if (in_array($study_group, $user['study_groups'])) {
								$applicable = true;
							}
						}

						if (in_array($user['uid'], $task['targeted_users'])) {
							$applicable = true;
						}

						if (!$applicable) continue;
					}

					//	dummy grade
					$task['grade'] = ['status' => 'unanswered'];

					//	if has a set answer for this user, use that
					if (isset($task['answers_by_uid'][$user['uid']])) {
						$task['answer'] =& $task['answers_by_uid'][$user['uid']];

						//	try to refer to last grade
						if (count($task['answer']['grades']) < 1) {
							$task['grade']['status'] = 'unchecked';
						} else {

							//	remove non admin grades
							foreach ($task['answer']['grades'] as $grade_id => $grade) {
								if (!isset($admins[$group['group_id']]) || !array_key_exists($grade['uid'], $admins[$group['group_id']])) {
									unset($task['answer']['grades'][$grade_id]);
								}
							}

							//	sort by latest creation date first and unchecked last
							uasort($task['answer']['grades'], function($a, $b) { 
								$status_score = ($a['status'] == 'unchecked' ? 1 : 0) - ($b['status'] == 'unchecked' ? 1 : 0);
								if ($status_score != 0) return $status_score;
								return $b['created'] - $a['created']; 
							});

							$key = array_keys($task['answer']['grades'])[0];
							$task['grade'] = $task['answer']['grades'][$key];
						}
					}

					unset($task['answers_by_uid'], $task['study_groups'], $task['targeted_users']);
					$group['tasks'][$task['task_id']] =& $task;

					unset($task);
				}
			}

			unset($group);
		}
		unset($user);
	}

	return $users;
}
