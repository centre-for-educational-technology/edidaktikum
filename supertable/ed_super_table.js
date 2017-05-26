

{	//	generator


	function make_name() {
		var first_names = ['Toomas', 'Juhan', 'Ilmar', 'Pärt', 'Anne', 'Terje', 'Jaana', 'Mari', 'Peeter', 'Liisa', 'Jaak', 'Elina', 'Mart', 'Maarja'];
		var last_names = ['Sepp', 'Tungal', 'Koidula', 'Sillamäe', 'Kingsepp', 'Poher', 'Tamm', 'Vaher', 'Kask', 'Puu', 'Lumi', 'Pohl', 'Maasikas', 'Kukeseen'];
		return first_names[Math.floor(Math.random() * first_names.length)] + " " + last_names[Math.floor(Math.random() * last_names.length)];
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
		var date = new Date(Math.random() * 2000000000000);
		date = "<br>" + date.getDate() + "/" + date.getMonth() + "/" + date.getYear();
		var r = Math.random();
		if (r < 0.7) return 'Kodune ülesanne ' + ++home_task_counter + date;
		if (r < 0.9) return 'Kontrolltöö ' + ++test_counter + date;
		return 'Eksam ' + ++exam_counter + date;
		
	}

	var task_id_counter = 0;
	function make_task() {
		return {
			'id' : task_id_counter++,
			'study_group' : make_study_group(),
			'due_date' : make_date(),
			'include_ids' : make_include_ids(),
			'title' : make_title(),
			'can_grade' : Math.random() < 0.8,
		}
	}
	
	function make_status() {
		var r = Math.random();
		if (r < 0.5) return 'accepted';
		if (r < 0.75) return 'rejected';
		if (r < 0.9) return 'unanswered';
		return 'unchecked';
	}
	
	function make_answer(task, user) {
		var stat = make_status();
		var grade = undefined;
		if (task.can_grade) {
			if (stat == 'accepted') {
				grade = 50 + Math.floor(Math.random() * 50);
			} else if (stat == 'rejected') {
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


{	//	generating

	var test_data = {
		'rows' : [],
		'cols' : [
			{'title' : 'name', 'sticky' : 'before', 'css_class' : 'col_header'}, 
			{'title' : 'age', 'group' : 'Personal Information', 'size' : 70},
			{'title' : 'height', 'group' : 'Personal Information', 'size' : 80}
		]
	}

	var test_tasks = []
	for (var i = 0; i < 10; i++) {
		var task = make_task()
		test_tasks.push(task);
		test_data.cols.push({
			'title' : task.title, 'id' : task.id, 'group' : 'Study Results', 'data' : task, 'sort_key' : 'grade'
		});
	}

	for (var i = 0; i < 30; i++) {
		var person = make_person();
		for (var j = 0; j < test_tasks.length; j++) {
			person[test_tasks[j].id] = make_answer(test_tasks[j], person);
		}
		test_data.rows.push({
			'id' : person.id, 'data' : person
		});
	}
}





window.addEventListener("load", function() {
	var ed = new edf.table();

	console.log(test_data.rows);
	console.log(test_data.cols);

	ed.add_rows(test_data.rows);

	ed.add_cols(test_data.cols);

	ed.header_row.size = 50;

	ed.add_function("Mean Grade", undefined, "Study Results", function(values) {
		var total = 0;
		var count = 0;
		for (var i = 0; i < values.length; i++) {
			if (edf.isdef(values[i].grade)) {
				total += values[i].grade;
				count++;
			}
		}
		return Math.round((total / count) * 10) / 10;
	});

	ed.add_function("% Accepted", undefined, "Study Results", function(values) {
		var total = 0;
		var count = 0;
		for (var i = 0; i < values.length; i++) {
			if (values[i].status === "accepted") count++;
			if (values[i].status != "unanswered" && values[i].status != "unchecked") total++;
		}
		return (Math.round((count / total * 100) * 10) / 10) + "%";
	});

	document.body.appendChild(ed.el);
	ed.initialize();
});




