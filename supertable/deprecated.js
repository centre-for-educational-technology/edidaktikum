{	//	absolute_manager

	edf.absolute_manager = function(el) {
		this.el = el;
		this.el.setAttribute
		this.registry[el] = this;
	}

	edf.absolute_manager.prototype.init = function() {
		var cs = getComputedStyle(el);
		this.left_val   = (cs.left != "")   ? edf.to_number(cs.left)   : undefined;
		this.right_val  = (cs.right != "")  ? edf.to_number(cs.right)  : undefined;
		this.top_val    = (cs.top != "")    ? edf.to_number(cs.top)    : undefined;
		this.bottom_val = (cs.bottom != "") ? edf.to_number(cs.bottom) : undefined;
		this.width_val  = (cs.width != "")  ? edf.to_number(cs.width)  : undefined;
		this.height_val = (cs.height != "") ? edf.to_number(cs.height) : undefined;
	}

	edf.absolute_manager.prototype.registry = {};
	edf.absolute_manager.prototype.registry_count = 0;
	
	edf.absolute_manager.prototype.register = function() {
		this.el.setAttribute("data-absolute_manager_id", this.registry_count);
		this.registry[this.registry_count] = this;
	}
	
	edf.absolute_manager.prototype.unregister = function() {
		//var id = this.el.get
		this.el.removeAttribute("data-absolute_manager_id");
		
	}

	Object.defineProperty(edf.absolute_manager.prototype, "parent_manager", {
		'get' : function() {
			if (this.el.parentElement !== null) return this.registry[this.el.parentElement];
			return undefined;
		}
	});

	Object.defineProperty(edf.absolute_manager.prototype, "parent_width", {
		'get' : function() {
			if (edf.isdef(this.parent_manager)) return this.parent_manager.width;
			if (edf.isdef(this.el.parentElement)) return this.el.parentElement.getBoundingClientRect().width;
			return undefined;
		}
	});

	Object.defineProperty(edf.absolute_manager.prototype, "parent_height", {
		'get' : function() {
			if (edf.isdef(this.parent_manager)) return this.parent_manager.height;
			if (edf.isdef(this.el.parentElement)) return this.el.parentElement.getBoundingClientRect().height;
			return undefined;
		}
	});

	Object.defineProperty(edf.absolute_manager.prototype, "left", {
		'get' : function() { 
			if (edf.isdef(this.left_val)) return this.left_val;
			if (edf.isdef(this.right_val)) return this.parent_width - (this.right_val + this.width);
			return undefined;
		},
		'set' : function(v) { this.left_val = v; this.el.style.left = v + "px"; }
	});

	Object.defineProperty(edf.absolute_manager.prototype, "right", {
		'get' : function() { 
			if (edf.isdef(this.right_val)) return this.right_val;
			if (edf.isdef(this.left_val)) return this.parent_width - (this.left_val + this.width);
			return undefined;
		},
		'set' : function(v) { this.right_val = v; this.el.style.right = v + "px"; }
	});

	Object.defineProperty(edf.absolute_manager.prototype, "top", {
		'get' : function() { 
			if (edf.isdef(this.top_val)) return this.top_val;
			if (edf.isdef(this.bottom_val)) return this.parent_height - (this.bottom_val + this.height);
			return undefined;
		},
		'set' : function(v) { this.top_val = v; this.el.style.top = v + "px"; }
	});

	Object.defineProperty(edf.absolute_manager.prototype, "bottom", {
		'get' : function() { 
			if (edf.isdef(this.bottom_val)) return this.bottom_val;
			if (edf.isdef(this.top_val)) return this.parent_height - (this.top_val + this.height);
			return undefined;
		},
		'set' : function(v) { this.bottom_val = v; this.el.style.bottom = v + "px"; }
	});

	Object.defineProperty(edf.absolute_manager.prototype, "width", {
		'get' : function() { 
			if (edf.isdef(this.width_val)) return this.width_val;
			if (edf.isdef(this.left_val) && edf.isdef(this.right_val)) return this.parent_width - (this.left_val + this.right_val);
			return this.el.getBoundingClientRect().width;
		 },
		'set' : function(v) { this.width_val = v; this.el.style.width = v + "px"; }
	});

	Object.defineProperty(edf.absolute_manager.prototype, "height", {
		'get' : function() { 
			if (edf.isdef(this.height_val)) return this.height_val;
			if (edf.isdef(this.top_val) && edf.isdef(this.bottom_val)) return this.parent_height - (this.top_val + this.bottom_val);
			return this.el.getBoundingClientRect().height;
		 },
		'set' : function(v) { this.height_val = v; this.el.style.height = v + "px"; }
	});

}


function test() {
	
	
	var n = 1000000;
	
	var el = document.createElement("div");
	document.body.appendChild(el);
	
	var dumm = {};
	dumm[0] = el;
	for (var i = 1; i < 1000; i++) {
		var e = document.createElement("div");
		document.body.appendChild(e);
		dumm[i] = e;
	}
	
	el.style.left = "100px";
	el.style.top = "120px";
	el.style.width = "100px";
	el.style.height = "100px";
	el.style.transform = "translate(100px,120px)";
	el.setAttribute("data-id", 0);
	el.setAttribute("data-left", 100);
	el.setAttribute("data-top", 120);
	el.left = 100;
	el.top = 120;
	dumm[0].left = 100;
	dumm[0].top = 120;
	
	edf.elapsed("start");
	for (var i = 0; i < n; i++) {
		var left = el.getAttribute("data-left");
		var top = el.getAttribute("data-top");

		//el.style.left = top + "px";
		//el.style.top = left + "px";
	}
	edf.elapsed("data attr");
		for (var i = 0; i < n; i++) {
		var left = el.getAttribute("data-left");


		//el.style.left = top + "px";
		//el.style.top = left + "px";
	}
	edf.elapsed("data attr opt");
	for (var i = 0; i < n; i++) {
		var left = edf.to_number(el.style.left);
		var top = edf.to_number(el.style.top);
		//el.style.left = top + "px";
		//el.style.top = left + "px";
	}
	var extract_left = /left: (\d*)/;
	var extract_numbers = /(\d*)/;
	edf.elapsed("style cast");	
	for (var i = 0; i < n; i++) {
		var left = parseInt(el.style.left.length);
		var top = parseInt(el.style.top.length);
		//var top = extract_numbers.exec(el.style.top)[0];
		//console.log(top);
		//el.style.left = top + "px";
		//el.style.top = left + "px";
	}
	edf.elapsed("style cast opt");
	for (var i = 0; i < n; i++) {
		var ext = extract_numbers.exec(el.style.transform);
		var left = parseInt(ext[0]);
		var top = parseInt(ext[1]);
		//el.style.left = top + "px";
		//el.style.top = left + "px";
	}
	edf.elapsed("translate cast");
	for (var i = 0; i < n; i++) {
		var left = dumm[el.getAttribute("data-id")].left;
		var top = dumm[el.getAttribute("data-id")].top;
		//el.style.left = top + "px";
		//el.style.top = left + "px";
	}
	edf.elapsed("data attr id encapsulated");
		for (var i = 0; i < n; i++) {
		var left = el.left;
		var top = el.top;
		//el.style.left = top + "px";
		//el.style.top = left + "px";
	}
	edf.elapsed("expando");
	
}



{
	edf.implement_i_size_style_shortcuts = function(proto, el_member_name) {
		el_member_name = edf.optional(el_member_name, "el");

		Object.defineProperty(proto, "width", {
			'get' : function() { return edf.to_number(this[el_member_name].style.width); },
			'set' : function(val) { this[el_member_name].style.width = val + "px"; }
		});
		Object.defineProperty(proto, "height", {
			'get' : function() { return edf.to_number(this[el_member_name].style.height); },
			'set' : function(val) { this[el_member_name].style.height = val + "px"; }
		});
	};

	edf.implement_i_position_style_shortcuts = function(proto, el_member_name) {
		el_member_name = edf.optional(el_member_name, "el");
	
		Object.defineProperty(proto, "left", {
			'get' : function() { return edf.to_number(this[el_member_name].style.left); },
			'set' : function(val) { this[el_member_name].style.left = val + "px"; }
		});
		Object.defineProperty(proto, "top", {
			'get' : function() { return edf.to_number(this[el_member_name].style.top); },
			'set' : function(val) { this[el_member_name].style.top = val + "px"; }
		});


		Object.defineProperty(proto, "right", {
			'get' : function() { return edf.to_number(this[el_member_name].style.right); },
			'set' : function(val) { this[el_member_name].style.right = val + "px"; }
		});
		Object.defineProperty(proto, "bottom", {
			'get' : function() { return edf.to_number(this[el_member_name].style.bottom); },
			'set' : function(val) { this[el_member_name].style.bottom = val + "px"; }
		});
	};

}


{	

	edf.styler = function(el) { return new edf.styler_obj(el); }
	edf.styler_obj = function(el) { this.el = el; }

	Object.defineProperty(edf.styler_obj.prototype, "left", {
		'get' : function() { return edf.to_number(this.el.style.left); },
		'set' : function(val) { this.el.style.left = val + "px"; }
	});
	Object.defineProperty(edf.styler_obj.prototype, "top", {
		'get' : function() { return edf.to_number(this.el.style.top); },
		'set' : function(val) { this.el.style.top = val + "px"; }
	});
	Object.defineProperty(edf.styler_obj.prototype, "right", {
		'get' : function() { return edf.to_number(this.el.style.right); },
		'set' : function(val) { this.el.style.right = val + "px"; }
	});
	Object.defineProperty(edf.styler_obj.prototype, "bottom", {
		'get' : function() { return edf.to_number(this.el.style.bottom); },
		'set' : function(val) { this.el.style.bottom = val + "px"; }
	});
	Object.defineProperty(edf.styler_obj.prototype, "width", {
		'get' : function() { return edf.to_number(this.el.style.width); },
		'set' : function(val) { this.el.style.width = val + "px"; }
	});
	Object.defineProperty(edf.styler_obj.prototype, "height", {
		'get' : function() { return edf.to_number(this.el.style.height); },
		'set' : function(val) { this.el.style.height = val + "px"; }
	});

}


{

	edf.time_cache = function(getter, interval) {
		this.interval = edf.optional(interval, 40);
		this.next = Date.now() + this.interval;
		this.value = getter();
		this.get_value = function() {
			if (Date.now() > this.next) {
				this.value = getter();
				this.next = Date.now() + this.interval;
			}
			return this.value;
		}
	}
}




{
	edf.precompute_style = function(el) {
		if (!edf.isdef(edf.precompute_style.box)) {
			var box = document.createElement("div");
			box.style = "position:fixed; opacity:0";
			box.innerHTML = "style precompute box";
			edf.precompute_style.box = box;
			document.body.appendChild(box);
		}

		var parent = el.parentElement;
		var next = el.nextSibling;

		edf.precompute_style.box.appendChild(el);
		var cs = getComputedStyle(el);
		edf.precompute_style.box.removeChild(el);

		if (parent !== null) {
			if (next !== null) {
				parent.insertBefore(el, next);
			} else {
				parent.appendChild(el);
			}
		}

		return cs;
	}

}



{	//	edf.table_row

	edf.table_row = function(data, table) {
		this.is_culled = true;
		this.table = table;
		this.data = data;
		this.cells = [];
		this.el = edf.create_element("div", "row_header");
		this.splitter = edf.create_element("div", "splitter", this.el);
		this.content = edf.create_element("div", "content", this.el);

		new edf.drag_handler(this.splitter, "left", function(dx, dy) {
			this.height += dy;
			this.table.render_vertical_positions();
		}.bind(this));
	}

	edf.table_row.prototype.set_row_attribute = function(name, value) {
		this.el.setAttribute(name, value);
		for (var i = 0; i < this.cells.length; i++) {
			this.cells[i].el.setAttribute(name, value);
		}
	}

	edf.table_row.prototype.render = function() {
		if (edf.isdef(this.renderer)) {
			this.content.innerHTML = this.renderer(this);
		} else {
			this.content.innerHTML = this.table.row_renderer(this);
		}		
	}

	edf.table_row.prototype.cull = function() {
		if (this.is_culled) return;
		this.table.elements.row_headers.removeChild(this.el);
		this.is_culled = true;
	}

	edf.table_row.prototype.uncull = function() {
		if (!this.is_culled) return;
		this.table.elements.row_headers.appendChild(this.el);
		this.is_culled = false;
	}

	edf.implement_i_size_style_shortcuts(edf.table_row.prototype);
	edf.implement_i_position_style_shortcuts(edf.table_row.prototype);

}

{	//	edf.table_col

	edf.table_col = function(data, table) {
		this.is_culled = true;
		this.table = table;
		this.data = data;
		this.cells = [];
		this.el = edf.create_element("div", "col_header");
		this.splitter = edf.create_element("div", "splitter", this.el);
		this.content = edf.create_element("div", "content", this.el);

		new edf.drag_handler(this.splitter, "left", function(dx, dy) {
			this.width += dx;
			this.table.render_horizontal_positions();
		}.bind(this));
	}



	edf.table_col.prototype.set_col_attribute = function(name, value) {
		this.el.setAttribute(name, value);
		for (var i = 0; i < this.cells.length; i++) {
			this.cells[i].el.setAttribute(name, value);
		}
	}

	edf.table_col.prototype.render = function() {
		if (edf.isdef(this.renderer)) {
			this.content.innerHTML = this.renderer(this);
		} else {
			this.content.innerHTML = this.table.col_renderer(this);
		}
	}

	edf.table_col.prototype.cull = function() {
		if (this.is_culled) return;
		this.table.elements.col_headers.removeChild(this.el);
		this.is_culled = true;
	}

	edf.table_col.prototype.uncull = function() {
		if (!this.is_culled) return;
		this.table.elements.col_headers.appendChild(this.el);
		this.is_culled = false;
	}
	
	edf.implement_i_size_style_shortcuts(edf.table_col.prototype);
	edf.implement_i_position_style_shortcuts(edf.table_col.prototype);

}





{	//	edf.table

	edf.table = function(row_objects, col_objects, cell_objects, cell_object_interpreter, row_renderer, col_renderer, cell_renderer) {
		this.rows = [];
		this.cols = [];
		this.cells = [];
		
		this.cells_width = 0;
		this.cells_height = 0;

		this.rows_by_id = {};
		this.cols_by_id = {};

		//	layout
		this.el = document.createElement("div");
		this.el.className = "edf_table";
		this.width = 800;
		this.height = 400;
		this.build_time_attach();
		this.elements = {};

		//	left
		this.elements.left_panel = edf.create_element("div", "left_panel", this.el);
		this.elements.row_headers = edf.create_element("div", "row_headers", this.elements.left_panel);
		this.elements.left_splitter = edf.create_element("div", "left_splitter", this.el);
		this.elements.left_splitter.setAttribute("data-split_size", edf.to_number(getComputedStyle(this.elements.left_splitter).width));
		new edf.drag_handler(this.elements.left_splitter, "left", function(dx, dy) { this.left_split += dx; }.bind(this));


		//	top
		this.elements.top_panel = edf.create_element("div", "top_panel", this.el);
		this.elements.col_headers = edf.create_element("div", "col_headers", this.elements.top_panel);
		this.elements.top_splitter = edf.create_element("div", "top_splitter", this.el);
		this.elements.top_splitter.setAttribute("data-split_size", edf.to_number(getComputedStyle(this.elements.top_splitter).height));
		new edf.drag_handler(this.elements.top_splitter, "left", function(dx, dy) { this.top_split += dy; }.bind(this));

		//	right
		this.elements.right_panel = edf.create_element("div", "right_panel", this.el);
		this.elements.row_statistics = edf.create_element("div", "row_statistics", this.elements.right_panel);
		this.elements.right_splitter = edf.create_element("div", "right_splitter", this.el);
		this.elements.right_splitter.setAttribute("data-split_size", edf.to_number(getComputedStyle(this.elements.right_splitter).width));
		new edf.drag_handler(this.elements.right_splitter, "left", function(dx, dy) { this.right_split -= dx; }.bind(this));

		//	bottom
		this.elements.bottom_panel = edf.create_element("div", "bottom_panel", this.el);
		this.elements.col_statistics = edf.create_element("div", "col_statistics", this.elements.bottom_panel);
		this.elements.bottom_splitter = edf.create_element("div", "bottom_splitter", this.el);
		this.elements.bottom_splitter.setAttribute("data-split_size", edf.to_number(getComputedStyle(this.elements.bottom_splitter).height));
		new edf.drag_handler(this.elements.bottom_splitter, "left", function(dx, dy) { this.bottom_split -= dy; }.bind(this));

		//	middle
		this.elements.middle_panel = edf.create_element("div", "middle_panel", this.el);
		this.elements.cells = edf.create_element("div", "cells", this.elements.middle_panel);
		this.elements.middle_panel.addEventListener("mousewheel", function(e) {
			var x = e.deltaX / (this.cells_width / 500);
			var y = e.deltaY / (this.cells_height / 500);
			this.horizontal_scroll_bar.scroll_px(x, y);
			this.vertical_scroll_bar.scroll_px(x, y);
			e.preventDefault();
		}.bind(this));

		this.horizontal_scroll_bar = new edf.scroll_bar(function(nx, ny) { this.scroll_x = nx; this.render_culling(); }.bind(this), true, false);
		this.elements.horizontal_scroll_bar = this.horizontal_scroll_bar.el;
		this.el.appendChild(this.elements.horizontal_scroll_bar);

		this.vertical_scroll_bar = new edf.scroll_bar(function(nx, ny) { this.scroll_y = ny; this.render_culling(); }.bind(this), false, true);
		this.el.appendChild(this.vertical_scroll_bar.el);
		this.elements.vertical_scroll_bar = this.vertical_scroll_bar.el;
		this.el.appendChild(this.elements.vertical_scroll_bar);

		//	buttons
		this.elements.resize_thumb = edf.create_element("div", "resize_thumb", this.el);
		new edf.drag_handler(this.elements.resize_thumb, "left", function(dx, dy) { 
			var scroll_x = this.horizontal_scroll_bar.scroll_x;
			var scroll_y = this.vertical_scroll_bar.scroll_y;

			this.width += dx; 
			this.height += dy; 

			this.horizontal_scroll_bar.scroll_x = scroll_x;
			this.vertical_scroll_bar.scroll_y = scroll_y;
		}.bind(this));

		this.elements.add_row_statistics = edf.create_element("div", "add_row_statistics", this.el);

		//	args
		if (edf.isdef(row_renderer)) this.row_renderer = row_renderer;
		if (edf.isdef(col_renderer)) this.col_renderer = col_renderer;
		if (edf.isdef(cell_renderer)) this.cell_renderer = cell_renderer;
		this.import_data(row_objects, col_objects, cell_objects, cell_object_interpreter);

		//	init	
		this.left_split = this.default_cell_width;
		this.top_split = this.default_cell_height;
		this.right_split = 0;
		this.bottom_split = 0;
		this.render_horizontal_positions();
		this.render_vertical_positions();
		this.render_contents();
		this.render_culling();
		this.build_time_detach();
	}

	//	rendering

	edf.table.prototype.render_culling = function() {
		var left = this.scroll_x * this.scroll_x_range;
		var right = left + this.visible_width;
		var top = this.scroll_y * this.scroll_y_range;
		var bottom = top + this.visible_height;

		for (var i = 0; i < this.cols.length; i++) {
			var col = this.cols[i];
			if (col.left + col.width < left || col.left > right) {
				col.cull();
				for (var j = 0; j < col.cells.length; j++) {
					col.cells[j].cull();
					col.cells[j].must_cull = true;
				}
			} else {
				col.uncull();
				for (var j = 0; j < col.cells.length; j++) {
					col.cells[j].must_cull = false;
				}
			}
		}

		for (var i = 0; i < this.rows.length; i++) {
			var row = this.rows[i];
			if (row.top + row.height < top || row.top > bottom) {
				row.cull();
				for (var j = 0; j < row.cells.length; j++) {
					row.cells[j].cull();
				}
			} else {
				row.uncull();
				for (var j = 0; j < row.cells.length; j++) {
					if (!row.cells[j].must_cull) row.cells[j].uncull();
				}
			}
		}
	}

	edf.table.prototype.render_vertical_positions = function() {
		this.cells_height = 0;
		for (var i = 0; i < this.rows.length; i++) {
			this.rows[i].top = this.cells_height;
			this.cells_height += this.rows[i].height;
			this.rows[i].set_row_attribute("data-nth_row", i % 2 ? "odd" : "even");
		}
		for (var i = 0; i < this.cells.length; i++) {
			this.cells[i].top = this.cells[i].row.top;
			this.cells[i].height = this.cells[i].row.height;
		}
	}

	edf.table.prototype.render_horizontal_positions = function() {
		this.cells_width = 0;
		for (var i = 0; i < this.cols.length; i++) {
			this.cols[i].left = this.cells_width;
			this.cells_width += this.cols[i].width;
			this.cols[i].set_col_attribute("data-nth_col", i % 2 ? "odd" : "even");
		}
		for (var i = 0; i < this.cells.length; i++) {
			this.cells[i].left = this.cells[i].col.left;
			this.cells[i].width = this.cells[i].col.width;
		}
	}

	edf.table.prototype.render_contents = function() {
		for (var i = 0; i < this.cols.length; i++) this.cols[i].render();
		for (var i = 0; i < this.rows.length; i++) this.rows[i].render();
		for (var i = 0; i < this.cells.length; i++) this.cells[i].render();
	}

	
	edf.table.prototype.import_data = function(row_objects, col_objects, cell_objects, cell_object_interpreter) {
		//	arguments
		row_objects = edf.optional(row_objects, []);
		col_objects = edf.optional(col_objects, []);
		cell_objects = edf.optional(cell_objects, []);
		if (edf.isdef(cell_object_interpreter)) this.cell_object_interpreter = cell_object_interpreter;

		//	import
		for (var i = 0; i < row_objects.length; i++) {
			var row = new edf.table_row(row_objects[i], this);
			row.width = this.default_cell_width;
			row.height = this.default_cell_height;
			row.left = 0;
			this.rows_by_id[row.data.id] = row;
			this.rows.push(row);
		}

		for (var i = 0; i < col_objects.length; i++) {
			var col = new edf.table_col(col_objects[i], this);
			col.width = this.default_cell_width;
			col.height = this.default_cell_height;
			col.top = 0;
			this.cols_by_id[col.data.id] = col;
			this.cols.push(col);
		}
		

		for (var i = 0; i < cell_objects.length; i++) {
			var cell = new edf.table_cell(cell_objects[i], this);
			var cell_standard_object = this.cell_object_interpreter(cell_objects[i]);
			
			cell.row = this.rows_by_id[cell_standard_object.row_id];
			cell.row.cells.push(cell);
			
			cell.col = this.cols_by_id[cell_standard_object.col_id];
			cell.col.cells.push(cell);
			
			this.cells.push(cell);
		}
	}

	//	defaults

	edf.table.prototype.cell_object_interpreter = function(cell_object) { 
		return { 'row_id' : cell_object.row_id, 'col_id' : cell_object.col_id }; 
	}

	edf.table.prototype.row_renderer = function(row) {
		for (var first_member in row.data) return first_member.toString();
	}

	edf.table.prototype.col_renderer = function(col) {
		for (var first_member in col.data) return first_member.toString();
	}

	edf.table.prototype.cell_renderer = function(cell) {
		for (var first_member in cell.data) return first_member.toString();
	}

	edf.table.prototype.default_cell_width = 160;
	edf.table.prototype.default_cell_height = 26;

	//	scrolling

	Object.defineProperty(edf.table.prototype, "visible_width", {
		'get' : function() { 
			var right = this.elements.middle_panel.style.right;
			if (edf.isdef(right)) {
				var left = this.elements.middle_panel.style.left;
				if (edf.isdef(left)) {
					return this.width - edf.to_number(right) - edf.to_number(left);
				}
			}
			return this.elements.middle_panel.getBoundingClientRect().width;
		}
	});

	Object.defineProperty(edf.table.prototype, "visible_height", {
		'get' : function() { 
			var bottom = this.elements.middle_panel.style.bottom;
			if (edf.isdef(bottom)) {
				var top = this.elements.middle_panel.style.top;
				if (edf.isdef(top)) {
					return this.height - edf.to_number(bottom) - edf.to_number(top);
				}
			}
			return this.elements.middle_panel.getBoundingClientRect().height;
		}
	});

	Object.defineProperty(edf.table.prototype, "scroll_x_range", {
		'get' : function() { return this.cells_width - this.visible_width; }
	});

	Object.defineProperty(edf.table.prototype, "scroll_x", {
		'get' : function() { return -edf.to_number(this.elements.col_headers.style.transform) / this.scroll_x_range; },
		'set' : function(val) {
			var x = -val * this.scroll_x_range;
			var y = -this.scroll_y * this.scroll_y_range;
			this.elements.col_headers.style.transform = "translateX(" + x + "px)";
			this.elements.cells.style.transform = "translate(" + x + "px," + y + "px)";
		}
	});

	Object.defineProperty(edf.table.prototype, "scroll_y_range", {
		'get' : function() { return this.cells_height - this.visible_height; }
	});

	Object.defineProperty(edf.table.prototype, "scroll_y", {
		'get' : function() { return -edf.to_number(this.elements.row_headers.style.transform) / this.scroll_y_range; },
		'set' : function(val) {
			var y = -val * this.scroll_y_range;
			var x = -this.scroll_x * this.scroll_x_range;
			this.elements.row_headers.style.transform = "translateY(" + y + "px)";
			this.elements.cells.style.transform = "translate(" + x + "px," + y + "px)";
		}
	});

	//	outer

	Object.defineProperty(edf.table.prototype, "width", {
		'get' : function() { return edf.to_number(this.el.style.width); },
		'set' : function(val) { this.el.style.width = val + "px"; }
	});

	Object.defineProperty(edf.table.prototype, "height", {
		'get' : function() { return edf.to_number(this.el.style.height); },
		'set' : function(val) { this.el.style.height = val + "px"; }	
	});

	//	layout management

	Object.defineProperty(edf.table.prototype, "left_split", {
		'get' : function() { return edf.to_number(this.elements.left_splitter.style.left); },
		'set' : function(val) {
			var scroll = this.horizontal_scroll_bar.scroll_x;
			var split_size = Number(this.elements.left_splitter.getAttribute("data-split_size"));
			val = edf.clamp(0, val, this.width - this.right_split - split_size * 2);
			this.elements.left_splitter.style.left = val + "px";
			this.elements.left_panel.style.width = val + "px";	
			this.elements.top_panel.style.left = (val + split_size) + "px";
			this.elements.bottom_panel.style.left = (val + split_size) + "px";
			this.elements.middle_panel.style.left = (val + split_size) + "px";
			this.elements.horizontal_scroll_bar.style.left = (val + split_size) + "px";
			this.horizontal_scroll_bar.scroll_x = scroll;
		}
	});

	Object.defineProperty(edf.table.prototype, "right_split", {
		'get' : function() { return edf.to_number(this.elements.right_splitter.style.right); },
		'set' : function(val) {
			var scroll = this.horizontal_scroll_bar.scroll_x;
			var split_size = Number(this.elements.right_splitter.getAttribute("data-split_size"));
			val = edf.clamp(0, val, this.width - this.left_split - split_size * 2);
			this.elements.right_splitter.style.right = val + "px";
			this.elements.right_panel.style.width = val + "px";	
			this.elements.top_panel.style.right = (val + split_size) + "px";
			this.elements.bottom_panel.style.right = (val + split_size) + "px";
			this.elements.middle_panel.style.right = (val + split_size) + "px";
			this.elements.horizontal_scroll_bar.style.right = (val + split_size) + "px";
			this.elements.vertical_scroll_bar.style.right = (val + split_size) + "px";
			this.horizontal_scroll_bar.scroll_x = scroll;
		}
	});

	Object.defineProperty(edf.table.prototype, "top_split", {
		'get' : function() { return edf.to_number(this.elements.top_splitter.style.top); },
		'set' : function(val) {
			var scroll = this.vertical_scroll_bar.scroll_y;
			var split_size = Number(this.elements.top_splitter.getAttribute("data-split_size"));
			val = edf.clamp(0, val, this.height - this.bottom_split - split_size * 2);
			this.elements.top_splitter.style.top = val + "px";
			this.elements.top_panel.style.height = val + "px";	
			this.elements.left_panel.style.top = (val + split_size) + "px";
			this.elements.right_panel.style.top = (val + split_size) + "px";
			this.elements.middle_panel.style.top = (val + split_size) + "px";
			this.elements.vertical_scroll_bar.style.top = (val + split_size) + "px";
			this.vertical_scroll_bar.scroll_y = scroll;
		}
	});

	Object.defineProperty(edf.table.prototype, "bottom_split", {
		'get' : function() { return edf.to_number(this.elements.bottom_splitter.style.bottom); },
		'set' : function(val) {
			var scroll = this.vertical_scroll_bar.scroll_y;
			var split_size = Number(this.elements.bottom_splitter.getAttribute("data-split_size"));
			val = edf.clamp(0, val, this.height - this.top_split - split_size * 2);
			this.elements.bottom_splitter.style.bottom = val + "px";
			this.elements.bottom_panel.style.height = val + "px";	
			this.elements.left_panel.style.bottom = (val + split_size) + "px";
			this.elements.right_panel.style.bottom = (val + split_size) + "px";
			this.elements.middle_panel.style.bottom = (val + split_size) + "px";
			this.elements.vertical_scroll_bar.style.bottom = (val + split_size) + "px";
			this.elements.horizontal_scroll_bar.style.bottom = (val + split_size) + "px";
			this.vertical_scroll_bar.scroll_y = scroll;
		}
	});

	//	util
	edf.table.prototype.build_time_attach = function() {
		this.el.style.opacity = "0";
		this.el.style.position = "fixed";
		document.body.appendChild(this.el);
	}

	edf.table.prototype.build_time_detach = function() {
		this.el.style.opacity = "";
		this.el.style.position = "";
		document.body.removeChild(this.el);
	}
}


{	//	edf.table.header_manager

	edf.table.header_manager = function() {
		this.items = [];
		this.sticky_items = [];
		this.groups = {};
		this.fetch_create_group();
	};

	edf.table.header_manager.prototype.fetch_create_group = function(group_name) {
		//	if group exists, just return
		group_name = edf.optional(group_name, 'undefined');
		if (edf.isdef(this.groups[group_name])) return this.groups[group_name];

		//	if no group, create
		var previous_names = Object.keys(this.groups);
		var previous = previous_names.length != 0 ? this.groups[previous_names.pop()] : undefined;
		this.groups[group_name] = { 'name' : group_name, 'items' : [], 'previous' : previous};

		//	create group item
		var item = edf.table.header.create_group_item(group_name);
		this.add(item, group_name);

		return this.groups[group_name];
	};

	edf.table.header_manager.prototype.remove_group_by_group = function(group) {
		var name_idx = Object.values(this.groups).indexOf(group);
		var name = Object.keys(name_idx);
		delete this.groups[name];
	};

	edf.table.header_manager.prototype.get_insert_index = function(group) {
		while (group !== undefined) {
			if (group.items.length > 0) return this.items.indexOf(group.items[group.items.length - 1]) + 1;
			group = group.previous;
		}
		return 0;
	};



	edf.table.header_manager.prototype.add = function(item, group_name) {
		item.group = this.fetch_create_group(group_name);
		this.items.splice(this.get_insert_index(item.group), 0, item);
		item.group.items.push(item);
		if (item.sticky === true) this.sticky_items.push(item);
	};

	edf.table.header_manager.prototype.rem = function(item) {
		if (item.sticky === true) this.sticky_items.splice(this.sticky_items.indexOf(item), 1);
		item.group.items.splice(item.group.items.indexOf(item), 1);
		if (item.group.items.length == 0) this.remove_group_by_group(item.group);
		this.items.splice(this.items.indexOf(item), 1);
	};

	edf.table.header_manager.prototype.get_visible = function(min, max, stickies) {
		var ret = [];
		for (var i = 0; i < this.items.length; i++) {
			var visible = this.items[i].test_visible(min, max);
			var sticky = (stickies === true) && this.items[i].sticky;
			if (visible || sticky) ret.push(this.items[i]);
		}

		return ret;
	};

	edf.table.header_manager.prototype.calculate_positions = function(offset) {
		var pos = edf.optional(offset, 0);
		for (var i = 0; i < this.items.length; i++) {
			this.items[i].pos = pos;
			pos += this.items[i].size;
			//if(this.items[1].name == "name") console.log(pos);
		}
	};
}