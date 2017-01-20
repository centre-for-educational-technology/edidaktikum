<?php

	//	$data is an array or keyed array where each kvp:
	//	key: optional row title
	//	value: array or keyed array where each kvp:
	//		key: optional column title
	//		value: cell data

	//	examples:
	//	both column and row headers: ['row_name_1' => ['col_name_1' => 'cell 1x1']]
	//	column headers only: [['col_name_1' => 'cell 1x1']]
	//	no headers: [['cell 1x1']]

	function ed_super_table_render($data) {
		return "";
		
		$tasks = ed_get_group_tasks(149, true, true, true);	
		$members = ed_get_group_members(149, true, true, true);
			
		$answers = [];
		for ($x = 0; $x < count($tasks); $x++) {
			for ($y = 0; $y < count($members); $y++) {
				array_push($answers, [
					'data' => ed_get_answer($tasks[$x]['nid'], $members[$y]['uid'], false, $members),
					'row' => $x,
					'col' => $y
				]);
			}
		}

		$table_data = [
			'rows' => $members,
			'cols' => $tasks,
			'cells' => $answers
		];

		$markup = "<script> var test_table_data = " . json_encode($table_data) . " ;</script>";

		drupal_add_js(drupal_get_path('module', 'edidaktikum') . '/ed_super_table.js');
		drupal_add_css(drupal_get_path('module', 'edidaktikum') . '/ed_super_table.css');

		return $markup;

	}






