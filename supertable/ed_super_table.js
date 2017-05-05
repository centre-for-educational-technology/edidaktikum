

{
	function make_name() {
		var first_names = ['Toomas', 'Juhan', 'Ilmar', 'Pärt', 'Anne', 'Terje', 'Jaana', 'Mari', 'Peeter', 'Liisa', 'Jaak', 'Elina', 'Mart', 'Maarja'];
		var last_names = ['Sepp', 'Tungal', 'Koidula', 'Sillamäe', 'Kingsepp', 'Poher', 'Tamm', 'Vaher', 'Kask', 'Puu', 'Lumi', 'Pohl', 'Maasikas', 'Kukeseen'];
		return first_names[Math.floor(Math.random() * 0.9999999 * first_names.length)] + " " + last_names[Math.floor(Math.random() * 0.9999999 * last_names.length)];
	}

	function make_study_group() {
		var groups = ['Triibulised', 'Kollased', 'Karvased', undefined, undefined, undefined, undefined, undefined, undefined];
		return groups[Math.round(Math.random() * groups.length)];
	}

	function make_date() {
		return Math.floor(Math.random() * 1000);
	}

	var person_id_counter = 0;
	function make_person() {
		return {
			'id' : person_id_counter++,
			'name' : make_name(),
			'age' : Math.round(Math.random() * 20 + 16),
			'height' : Math.round(Math.random() * 100 + 100),
			'study_group' : make_study_group()
		}
	}

	function make_include_ids() {
		var inc = [];
		for (var i = 0; i < person_id_counter; i++) {
			if (Math.random() < 0.1) inc.push(i);
		}
		return inc;
	}

	var home_task_counter = 0;
	var test_counter = 0;
	var exam_counter = 0;
	function make_title() {
		var r = Math.random();
		if (r < 0.7) return 'Kodune ülesanne ' + ++home_task_counter;
		if (r < 0.9) return 'Kontrolltöö ' + ++test_counter;
		return 'Eksam ' + ++exam_counter;
		
	}

	var task_id_counter = 0;
	function make_task() {
		return {
			'id' : task_id_counter++,
			'study_group' : make_study_group(),
			'due_date' : make_date(),
			'include_ids' : make_include_ids(),
			'title' : make_title(),
			'can_grade' : Math.random() < 0.8
		}
	}
	
	function make_status() {
		var r = Math.random();
		if (r < 0.5) return 'Accepted';
		if (r < 0.75) return 'Rejected';
		if (r < 0.9) return 'Unanswered';
		return 'Unchecked';
	}
	
	function make_answer(task, user) {
		var stat = make_status();
		var grade = undefined;
		if (task.can_grade) {
			if (stat == 'Accepted') {
				grade = 50 + Math.floor(Math.random() * 50);
			} else if (stat == 'Rejected') {
				grade = Math.floor(Math.random() * 49);
			}
		}
		
		return {
			'id' : Math.floor(Math.random() * 10000),
			'task_id' : task.id,
			'user_id' : user.id,
			'status' : stat,
			'grade' : grade,
			'modified_date' : make_date()
		}
	}
}

var test_table_data = {
	'rows' : [],
	'cols' : [],
	'cells' : [],
	'row_id_func' : function(cell) { return cell.user_id },
	'col_id_func' : function(cell) { return cell.task_id }
};

for (var i = 0; i < 100; i++) {
	test_table_data.rows.push(make_person());
}

for (var i = 0; i < 50; i++) {
	test_table_data.cols.push(make_task());
}

for (var y = 0; y < test_table_data.rows.length; y++) {
	for (var x = 0; x < test_table_data.cols.length; x++) {
		var task = test_table_data.cols[x];
		var user = test_table_data.rows[y];
		test_table_data.cells.push(make_answer(task, user));
	}
}


var divs = [];
window.addEventListener("load", function() {
	/*
	var statcols = {'Accepted' : 'rgba(220,255,220,1)', 'Rejected' : 'rgba(255,220,220,1)', 'Unanswered' : 'transparent', 'Unchecked' : 'rgba(255,255,220,1)'};
	var tt = new edf.table_old(test_table_data.rows, test_table_data.cols, test_table_data.cells, 
		function(answer) { return { 'row_id' : answer.user_id, 'col_id' : answer.task_id }; },
		function(member_row) { return member_row.data.name; },
		function(task_col) 	 { return task_col.data.title; },
		function(answer_cell) { return "<div style='background-color:" + statcols[answer_cell.data.status] + "'>" + (edf.isdef(answer_cell.data.grade) ? answer_cell.data.grade : "") + "</div>"; }
	);
	document.body.appendChild(tt.el);
	tt.init();
	*/

	//	make column groups
	var column_title_by_id = {};
	var column_groups = {
		'_' : ['Name'],
		'Personal Information' : ['Age', 'Height'],
		'Results' : []
	};
	for (var i = 0; i < test_table_data.cols.length; i++) {
		column_groups['Results'].push(test_table_data.cols[i].title);
		column_title_by_id[test_table_data.cols[i].id] = test_table_data.cols[i].title;
	}

	//	make rows
	var rows = [];
	for (var i = 0; i < test_table_data.rows.length; i++) {
		var row = test_table_data.rows[i];
		for (var j = 0; j < test_table_data.cells.length; j++) {
			if (test_table_data.cells[j].user_id == row.id) {
				test_table_data.cells[j].title = test_table_data.cells[j].status
				row[column_title_by_id[test_table_data.cells[j].task_id]] = test_table_data.cells[j];
			}
		}
		rows.push(row);
	}
	//console.log(column_groups);
	console.log(rows);

	var ed = new edf.table();

	ed.add_col('name', undefined, 150, true);
	ed.add_col('age', 'Personal Information');
	ed.add_col('height', 'Personal Information');
	for (var i = 0; i < test_table_data.cols.length; i++) {
		ed.add_col(test_table_data.cols[i].title, 'Study results', 150);
	}

	for (var i = 0; i < rows.length; i++) {
		ed.add_row(rows[i]);
	}

	var mean_grade_func = function(values) {
		var total = 0;
		var count = 0;
		for (var i = 0; i < values.length; i++) {
			if (edf.isdef(values[i].grade)) {
				total += values[i].grade;
				count++;
			}
		}
		return Math.round((total / count) * 10) / 10;
	};

	var percent_accepted_func = function(values) {
		var total = 0;
		var count = 0;
		for (var i = 0; i < values.length; i++) {
			if (values[i].status === "Accepted") count++;
			if (values[i].status != "Unanswered" && values[i].status != "Unchecked") total++;
		}
		return (Math.round((count / total * 100) * 10) / 10) + "%";
	}
	

	ed.add_function("Mean Grade", undefined, "Study results", mean_grade_func);
	ed.add_function("% Accepted", undefined, "Study results", percent_accepted_func);

	//console.log(edt);


	
	
	document.body.appendChild(ed.el);
	ed.initialize();
	//console.log(edf.rect.get(ed.el));

	var kekmax = 300;
	var kekmin = 100;

	var kekxm = 3;
	var kekx = kekmin + kekxm;
	
	var kekym = 4;
	var keky = kekmin + kekym;
	

	function kekmaster() {
		kekx += kekxm;
		if (kekx >= kekmax || kekx <= kekmin) {
			kekxm = -kekxm;
			keky += kekym;
			if (keky >= kekmax || keky <= kekmin) {
				kekym = -kekym;
			}
		}
		ed.set_camera(kekx, keky);
		setTimeout(kekmaster, 0);
	}

	//kekmaster();
});




