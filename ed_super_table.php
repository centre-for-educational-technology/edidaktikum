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

		//	test data
		$data = [
			'row1' => ['col1' => '1x1'],
			'row2' => ['col1' => '1x2']
		];

		/*
		$data = [
			['col1' => '1x1'],
			['col1' => '1x2']
		];

		$data = [
			['1x1'],
			['1x2']
		];

		$data = [
			'row1' => ['1x1'],
			'row2' => ['1x2']
		];
		*/
		

		if (count($data) < 1) return '';

		//	standardize data
		$has_row_titles = !isset($data[0]);
		$row_titles = [];

		$has_col_titles = !isset($data[key($data)][0]);
		$col_titles = [];

		foreach ($data as $row_title => $row_data) {
			if ($has_row_titles && !array_key_exists($row_title, $row_titles)) array_push($row_titles, $row_title);
			if (!$has_col_titles) continue;
			foreach ($row_data as $col_title => $cell_data) {
				if (!array_key_exists($col_title, $col_titles)) array_push($col_titles, $col_title);
			}
		}

		$markup = "

			<div data-super_table ></div>





		";

		drupal_add_js(drupal_get_path('module', 'edidaktikum') . '/ed_super_table.js');
		drupal_add_css(drupal_get_path('module', 'edidaktikum') . '/ed_super_table.css');

		return $markup;

	}






