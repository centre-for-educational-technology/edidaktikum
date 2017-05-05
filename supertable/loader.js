//	loader for supertable while wip


function super_table_loader(rows, cols) {
	var container = document.querySelector("#super_table_experiment");

	var table = new edf.table();

	for (var col_group in cols) {
		for (var i = 0; i < cols[col_group].length; i++) {
			table.add_col(cols[col_group][i], col_group, 150, cols[col_group][i] == 'Name');
		}
	}

	for (var row in rows) {
		table.add_row(rows[row]);
	}

	var mean_grade_func = function(values) {
		var total = 0;
		var count = 0;
		for (var i = 0; i < values.length; i++) {
			if (edf.isdef(values[i].grade)) {
				total += parseFloat(values[i].grade);
				count++;
			}
		}
		if (count == 0) return "";
		return Math.round((total / count) * 10) / 10;
	};
	table.add_function("Mean Grade", undefined, "Study Results", mean_grade_func);

	var percent_accepted_func = function(values) {
		var total = 0;
		var count = 0;
		for (var i = 0; i < values.length; i++) {
			if (values[i].status === "accepted") count++;
			if (values[i].status != "unanswered" && values[i].status != "unchecked") total++;
		}
		if (total == 0) return "";
		return (Math.round((count / total * 100) * 10) / 10) + "%";
	}
	table.add_function("% Accepted", undefined, "Study Results", percent_accepted_func);


	container.appendChild(table.el);
	table.initialize();
}