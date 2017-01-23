{	//edf namespace and basic utilities 

	window['edf'] = {
		'isdef' : function(x) { return typeof x !== 'undefined'; },
		'optional' : function(x, def) { return edf.isdef(x) ? x : def; },
		'filter' : function(collection, predicate) {
			var ret = [];
			for (var i = 0; i < collection.length; i++) {
				if (predicate(collection[i])) ret.push(collection[i]);
			}
			return ret;
		}
	}
}


{	//	edf.drag_handler

	/*
		generic drag handling utility
	
		constructor:
			el 			- DOM element 					- the element to click on to start the drag
			callback 	- function(delta_x, delta_y) 	- is called when mouse moves while dragging
			button 		- "left", "right", "middle" 	- determines the mouse button used for dragging
	*/

	edf.drag_handler = function (el, callback, button) {
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


{	//	edf.table_data

	/*
		standard data format

		interfaces:
			i_cell
				.row	- {}	- associated i_header object
				.col	- {}	- associated i_header object
				.data	- {}	- object data

			i_header
				.data	- {}	- object data
				.cells	- {}	- associated i_cell objects indexed by corresponding i_header object

		members: 
			rows		- [] of i_header	- array of i_header objects, order is guaranteed
			cols		- [] of i_header	- array of i_header objects, order is guaranteed
			cells		- [] of i_cell		- array of i_cell objects

		constructor: 
			refer to import_data
	*/

	edf.table_data = function(rows, cols, cells) {
		this.rows = [];
		this.cols = [];
		this.cells = [];

		import_data(rows, cols, cells);
	}

	{	//	width, height
		Object.defineProperty(edf.table_data.prototype, 'width', {
			'get' : function() { return this.cols.length; }
		});

		Object.defineProperty(edf.table_data.prototype, 'height', {
			'get' : function() { return this.rows.length; }
		});
	}

	{	//	import_data
		/*
			interfaces:
				i_cell_json
					.row	- Number	- row association with N'th row object in this table
					.col	- Number	- col association with N'th col object in this table
					.data	- {}		- cell data object

			arguments:
				rows	- []				- array of row objects
				cols	- []				- array of col objects
				cells	- [] of i_cell_json	- array of objects implementing i_cell_json

		*/

		edf.table_data.prototype.import_data = function(rows, cols, cells) {
			//	arguments
			rows = edf.optional(rows, []);
			cols = edf.optional(cols, []);
			cells = edf.optional(cells, []);

			//	import
			for (var i = 0; i < rows.length; i++) {
				var row = { 'data' : rows[i], 'cells' : {} };
				this.rows.push(row);
			}

			for (var i = 0; i < cols.length; i++) {
				var col = { 'data' : cols[i], 'cells' : {} };
				this.cols.push(col);
			}

			for (var i = 0; i < cells.length; i++) {
				var cell = cells[i];
				cell.row = this.rows[cells[i].row];
				cell.col = this.cols[cells[i].col];
				cell.row.cells[cell.col] = cell;
				cell.col.cells[cell.row] = cell;
				this.cells.push(cell);
			}
		}
	}

	edf.table_data.prototype.filter_rows = function(predicate) {
		this.rows = edf.filter(this.rows, function(row) { return predicate(row.data); });
	}

	edf.table_data.prototype.filter_cols = function(predicate) {
		this.cols = edf.filter(this.cols, function(col) { return predicate(col.data); });
	}

	edf.table_data.prototype.sort_rows = function(predicate) {
		this.rows.sort(predicate);
	}

	edf.table_data.prototype.sort_cols = function(predicate) {
		this.cols.sort(predicate);
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

	

});
