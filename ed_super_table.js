

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

{	//	super_drag_handler

	function super_drag_handler(el, callback, button) {
		this.button_mask = (button == "left" ? 1 : (button == "right" ? 2 : 4));
		this.callback = callback;

		el.addEventListener("mousedown", function(e) {
			if ((e.buttons & this.button_mask) != this.button_mask) return;
			this.last_clientX = e.clientX;
			this.last_clientY = e.clientY;
			document.addEventListener("mousemove", this.move_handler);
		}.bind(this));

		this.move_handler = function(e) {
			if ((e.buttons & this.button_mask) != this.button_mask) {
				document.removeEventListener("mousemove", this.move_handler);
				return;
			}
			var dx = e.clientX - this.last_clientX;
			var dy = e.clientY - this.last_clientY;
			this.last_clientX = e.clientX;
			this.last_clientY = e.clientY;

			this.callback(dx, dy);
		}.bind(this);
	}

}


{	//	super_table

	//	options
	//	lock horizontal / vertical cell spacers
	//	display horitzontal / vertical headers
	//	lock / unlock statistical rows

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

	super_table.prototype.resize_on_move = function(e) {
		var dx = e.clientX - this.last_clientX;
		var dy = e.clientY - this.last_clientY;

	};

	Object.defineProperty(super_table.prototype, 'width', {
		'get' : function() { return parseInt(this.el.style.width); },
		'set' : function(val) {	this.el.style.width = val + "px"; }
	});

	Object.defineProperty(super_table.prototype, 'height', {
		'get' : function() { return parseInt(this.el.style.height); },
		'set' : function(val) {	this.el.style.height = val + "px"; }
	});

	Object.defineProperty(super_table.prototype, 'stat_width', {
		'get' : function() { return parseInt(this.config_box.style.width); },
		'set' : function(val) {	
			this.stat_bottom.style.right = val + "px";
			this.stat_right.style.width = val + "px";
			this.config_box.style.width = val + "px";
		}
	});

	Object.defineProperty(super_table.prototype, 'stat_height', {
		'get' : function() { return parseInt(this.config_box.style.height); },
		'set' : function(val) {	
			this.stat_bottom.style.height = val + "px";
			this.stat_right.style.bottom = val + "px";
			this.config_box.style.height = val + "px";
		}
	});

	function super_table(el) {
		this.data = new super_table_data(data4);
		this.el = (typeof el !== 'undefined') ? el : document.createElement("div");
		this.el.className = "super_table";

		//	clone auto width
		this.width = this.el.getBoundingClientRect().width;
		this.height = 300;
	
		{	//	widget resize handles, level 0
			/*
			this.bottom_sizer = document.createElement("div");
			this.bottom_sizer.className = "bottom_sizer";
			this.el.appendChild(this.bottom_sizer);
			new super_drag_handler(this.bottom_sizer, function(x, y) {
				this.height += y;
			}.bind(this), "left");

			this.right_sizer = document.createElement("div");
			this.right_sizer.className = "right_sizer";
			this.el.appendChild(this.right_sizer);
			new super_drag_handler(this.right_sizer, function(x, y) {
				this.width += x;
			}.bind(this), "left");
			*/


			this.bottom_right_sizer = document.createElement("div");
			this.bottom_right_sizer.className = "bottom_right_sizer";
			this.el.appendChild(this.bottom_right_sizer);
			new super_drag_handler(this.bottom_right_sizer, function(x, y) {
				this.height += y;
				this.width += x;
			}.bind(this), "left");

			this.scroll_horizontal = document.createElement("div");
			this.scroll_horizontal.className = "scroll_horizontal";
			this.el.appendChild(this.scroll_horizontal);
		}

		{	//	stat and config partitions, level 1
			this.content = document.createElement("div");
			this.content.className = "content";
			this.el.appendChild(this.content);

			this.stat_right = document.createElement("div");
			this.stat_right.className = "stat_right";
			this.content.appendChild(this.stat_right);

			this.stat_bottom = document.createElement("div");
			this.stat_bottom.className = "stat_bottom";
			this.content.appendChild(this.stat_bottom);

			this.config_box = document.createElement("div");
			this.config_box.className = "config_box";
			this.content.appendChild(this.config_box);

			this.stat_width = 120;
			this.stat_height = 40;
		}
		/*
		this.top_bar = document.createElement("div");
		this.top_bar.className = "top_bar";
		this.el.appendChild(this.top_bar);

		this.bottom_bar = document.createElement("div");
		this.bottom_bar.className = "bottom_bar";
		this.el.appendChild(this.bottom_bar);

		this.scroll_box = document.createElement("div");
		this.scroll_box.className = "scroll_box";
		this.el.appendChild(this.scroll_box);
*/
		//this.create_table(this.data.width, this.data.height);
		
	}

}

window.addEventListener("load", function() {
	var testy = document.querySelector('[data-super_table]');
	new super_table(testy);
});
