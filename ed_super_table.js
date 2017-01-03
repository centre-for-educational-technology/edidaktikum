

var data1 = [
	['1x1', '2x1'],
	['2x1', '2x2']
];

var data2 = [
	{'col1' : '1x1', 'col2' : '2x1'},
	{'col1' : '1x2', 'col2' : '2x2'}
];

var data3 = {
	'row1' : ['1x1', '2x1'],
	'row2' : ['2x1', '2x2']
};

var data4 = {
	'row1' : {'col1' : '1x1', 'col2' : '2x1'},
	'row2' : {'col1' : '1x2', 'col2' : '2x2', 'col3' : '3x2'}
}

{	//	super_table_data

	function super_table_data(data) {
		var has_row_titles = !(data instanceof Array);
		var has_col_titles = !(data[Object.keys(data)[0]] instanceof Array);

		//	either use provided row titles or fill with empty strings
		this.row_titles = has_row_titles ? Object.keys(data) : Array.apply(null, Array(data.length)).map(String.prototype.valueOf,"");
		this.height = this.row_titles.length;

		//	either create a superset of column titles or fill with empty strings
		if (has_col_titles) {
			var temp = {};
			for (var y = 0; y < Object.keys(data).length; y++) {
				for (var col_key in data[Object.keys(data)[y]]) temp[col_key] = undefined;
			}
			this.col_titles = Object.keys(temp);
		} else {
			var len = 0;
			for (var y = 0; y < Object.keys(data).length; y++) {
				len = Math.max(data[Object.keys(data)[y]].length);
			}
			this.col_titles = Array.apply(null, Array(len)).map(String.prototype.valueOf,"")
		}
		this.width = this.col_titles.length;

		//	collect data into fixed array, any missing data is filled by an empty string
		this.data = new Array(this.height);

		if (has_col_titles) {
			for (var y = 0; y < Object.keys(data).length; y++) {
				this.data[y] = Array.apply(null, Array(this.width)).map(String.prototype.valueOf,"");
				var row = data[Object.keys(data)[y]];
				for (var x = 0; x < this.width; x++) {
					if (this.col_titles[x] in row) this.data[y][x] = row[this.col_titles[x]]
				}
			}
		} else {
			for (var y = 0; y < Object.keys(data).length; y++) {
				this.data[y] = Array.apply(null, Array(this.width)).map(String.prototype.valueOf,"");
				var row = data[Object.keys(data)[y]];
				for (var x = 0; x < row.length; x++) this.data[y][x] = row[x]
			}
		}

	};
}

{	//	super_table

	super_table.prototype.create_table = function(width, height) {
		if (typeof this.table !== 'undefined') this.el.removeChild(this.table);
		this.table = document.createElement("table");
		this.rows = [];
		this.cells = [];
		this.el.appendChild(this.table);

		for (var y = 0; y < this.data.height; y++) {
			var tr = document.createElement("tr");
			this.table.appendChild(tr);
			this.rows.push(tr);
			this.cells.push([]);

			for (var x = 0; x < this.data.width; x++) {
				var td = document.createElement("td");
				tr.appendChild(td);
				this.cells[y].push(td);
			}
		}
	};

	function super_table(el) {
		this.data = new super_table_data(data4);
		console.log(el);
		this.el = (typeof el !== 'undefined') ? el : document.createElement("div");
		this.el.className = "super_table";
		console.log(this.el);

		this.create_table(this.data.width, this.data.height);
		
	}

}

window.addEventListener("load", function() {
	var testy = document.querySelector('[data-super_table]');
	new super_table(testy);
});
