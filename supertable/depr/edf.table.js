

{	//	edf.table

	edf.table = function(row_objects, col_objects, cell_objects, cell_object_interpreter, row_renderer, col_renderer, cell_renderer) {
		this.rows_by_id = {};
		this.cols_by_id = {};

		this.rows = [];
		this.cols = [];
		this.cells = [];

		this.disable_secondary_render = false;

		this.el = edf.create_element("div", "edf_table");
		this.el.addEventListener("mousewheel", function(e) {
			var x = e.deltaX / (this.top_viewer.internal_width / 500);
			var y = e.deltaY / (this.left_viewer.internal_height / 500);
			this.horizontal_scroll.mod_px(x, y);
			this.vertical_scroll.mod_px(x, y);
			e.preventDefault();
		}.bind(this));

		//	left
		this.left_viewer = new edf.table_cell_viewer(this.rows);
		this.append_el(this.left_viewer.el, "left_viewer");
		this.left_splitter = new edf.slider(function(dx, dy) { this.left_split = dx; }.bind(this), true, false);
		this.append_el(this.left_splitter.el, "left_splitter");

		//	top
		this.top_viewer = new edf.table_cell_viewer(this.cols);
		this.append_el(this.top_viewer.el, "top_viewer");
		this.top_splitter = new edf.slider(function(dx, dy) { this.top_split = dy; }.bind(this), false, true);
		this.append_el(this.top_splitter.el, "top_splitter");

		//	right
		this.right_viewer = new edf.table_cell_viewer(this.rows_statistics);
		this.append_el(this.right_viewer.el, "right_viewer");
		this.right_splitter = new edf.slider(function(dx, dy) { this.right_split = dx; }.bind(this), true, false);
		this.append_el(this.right_splitter.el, "right_splitter");

		//	bottom
		this.bottom_viewer = new edf.table_cell_viewer(this.cols_statistics);
		this.append_el(this.bottom_viewer.el, "bottom_viewer");
		this.bottom_splitter = new edf.slider(function(dx, dy) { this.bottom_split = dy; }.bind(this), false, true);
		this.append_el(this.bottom_splitter.el, "bottom_splitter");
		
		//	middle
		this.middle_viewer = new edf.table_cell_viewer(this.cells);
		this.middle_viewer.horizontal_master = this.top_viewer;
		this.middle_viewer.vertical_master = this.left_viewer;

		this.append_el(this.middle_viewer.el, "middle_viewer");
		this.horizontal_scroll = new edf.slider(function(dx, dy) {
			this.top_viewer.move_to(dx, 0);
			this.top_viewer.cull();
			this.top_viewer.render();
			if (this.disable_secondary_render) return;
			this.middle_viewer.render();
		}.bind(this), true, false);
		this.append_el(this.horizontal_scroll.el, "horizontal_scroll");
		this.vertical_scroll = new edf.slider(function(dx, dy) {
			this.left_viewer.move_to(0, dy);
			this.left_viewer.cull();
			this.left_viewer.render();
			if (this.disable_secondary_render) return;
			this.middle_viewer.render();
		}.bind(this), false, true);
		this.append_el(this.vertical_scroll.el, "vertical_scroll");

		//	buttons
		this.resize_thumb = edf.create_element("div", "resize_thumb button", this.el);
		new edf.drag_handler(this.resize_thumb, 'left', function(dx, dy) {
			this.set_size(this.width + dx, this.height + dy);
		}.bind(this));

		this.add_row_statistics_button = edf.create_element("div", "add_row_statistics button", this.el);
		this.add_row_statistics_button.addEventListener("mouseup", function(e) {
			var items = [];

			for (var i = 0; i < this.data_shaders.length; i++) {
				items.push(edf.context_menu_item.from_title_description(this.data_shaders[i].title, this.data_shaders[i].description, function() {
					
				}.bind(this)));
			}

			new edf.context_menu(e.clientX, e.clientY, items);
		}.bind(this));


		//	args
		if (edf.isdef(row_renderer)) this.row_renderer = row_renderer;
		if (edf.isdef(col_renderer)) this.col_renderer = col_renderer;
		if (edf.isdef(cell_renderer)) this.cell_renderer = cell_renderer;
		this.import_data(row_objects, col_objects, cell_objects, cell_object_interpreter);
	};

	{	//	defaults

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
	}

	{	//	func
		edf.table.prototype.init = function() {
			this.left_viewer.measure_vertical();
			this.top_viewer.measure_horizontal();


			this.set_size(800, 400);
			this.splitter_size = this.left_splitter.thumb.getBoundingClientRect().width;


			this.left_splitter.set(this.default_cell_width / this.width, 0);
			this.top_splitter.set(0,this.default_cell_height / this.height);
			this.hide_rows_statistics(true);
			this.hide_cols_statistics(true);
			this.left_splitter.disable();
			this.top_splitter.disable();
			this.right_splitter.disable();
			this.bottom_splitter.disable();

			//this.render();
		}

		edf.table.prototype.render = function() {	
			this.left_viewer.cull();			
			this.top_viewer.cull();
			this.left_viewer.render();
			this.top_viewer.render();
			this.middle_viewer.render();
		}

		edf.table.prototype.hide_rows_statistics = function(yesno) {
			yesno = edf.optional(yesno, true);
			if (yesno) {
				this.right_splitter.clamp = false;
				this.right_splitter.set(1,1);
				this.right_splitter.el.style.opacity = 0;		
			} else {
				this.right_splitter.clamp = true;
				this.right_splitter.el.style.opacity = 1;
			}
		}

		edf.table.prototype.hide_cols_statistics = function(yesno) {
			yesno = edf.optional(yesno, true);
			if (yesno) {
				this.bottom_splitter.clamp = false;
				this.bottom_splitter.set(1,1);
				this.bottom_splitter.el.style.opacity = 0;
			} else {
				this.bottom_splitter.clamp = true;
				this.bottom_splitter.el.style.opacity = 1;
			}
		}
	
		edf.table.prototype.append_el = function(el, class_name) {
			el.className += " " + class_name;
			this.el.appendChild(el);
		};

		edf.table.prototype.set_size = function(width, height) {
			this.width = width; 
			this.height = height;

			edf.rect.set(this.el, undefined, undefined, width, height);
			edf.rect.set(this.left_splitter.el, undefined, undefined, width, height);
			edf.rect.set(this.right_splitter.el, undefined, undefined, width, height);
			edf.rect.set(this.top_splitter.el, undefined, undefined, width, height);
			edf.rect.set(this.bottom_splitter.el, undefined, undefined, width, height);


			this.left_splitter.reset_px();
			this.right_splitter.reset();
			this.top_splitter.reset_px();
			this.bottom_splitter.reset();
		};

		edf.table.prototype.import_data = function(row_objects, col_objects, cell_objects, cell_object_interpreter) {
			//	arguments
			row_objects = edf.optional(row_objects, []);
			col_objects = edf.optional(col_objects, []);
			cell_objects = edf.optional(cell_objects, []);
			if (edf.isdef(cell_object_interpreter)) this.cell_object_interpreter = cell_object_interpreter;

			//	import
			for (var i = 0; i < row_objects.length; i++) {
				var row = new edf.table_cell(row_objects[i]);
				row.renderer = this.row_renderer;
				row.width = this.default_cell_width;
				row.height = this.default_cell_height;
				this.rows_by_id[row.data.id] = row;
				this.rows.push(row);
			}

			for (var i = 0; i < col_objects.length; i++) {
				var col = new edf.table_cell(col_objects[i]);
				col.renderer = this.col_renderer;
				col.width = this.default_cell_width;
				col.height = this.default_cell_height;
				this.cols_by_id[col.data.id] = col;
				this.cols.push(col);
			}
			

			for (var i = 0; i < cell_objects.length; i++) {
				var cell = new edf.table_cell(cell_objects[i]);
				cell.renderer = this.cell_renderer;
				var cell_standard_object = this.cell_object_interpreter(cell_objects[i]);
				
				cell.row = this.rows_by_id[cell_standard_object.row_id];
				cell.row.cells.push(cell);
				
				cell.col = this.cols_by_id[cell_standard_object.col_id];
				cell.col.cells.push(cell);
				
				this.cells.push(cell);
			}
		};

		edf.table.prototype.add_row = function(col_object) {

		};

		edf.table.prototype.add_statistical_col = function(title, row_func) {

		};

	}

	{	//	splitters

		Object.defineProperty(edf.table.prototype, "left_split", {
			'get' : function() { return this.left_splitter.x; },
			'set' : function(v) {
				var px = v * this.width;
				edf.rect.set_width(this.left_viewer.el, px);
				px += this.splitter_size;
				edf.rect.set_x(this.middle_viewer.el, px);
				edf.rect.set_x(this.top_viewer.el, px);
				edf.rect.set_x(this.bottom_viewer.el, px);
				edf.rect.set_x(this.horizontal_scroll.el, px);
				px = (this.right_split - v) * this.width - 2 * this.splitter_size;
				edf.rect.set_width(this.middle_viewer.el, px);
				edf.rect.set_width(this.top_viewer.el, px);
				edf.rect.set_width(this.bottom_viewer.el, px);
				edf.rect.set_width(this.horizontal_scroll.el, px);
				this.horizontal_scroll.reset();
			}
		});

		Object.defineProperty(edf.table.prototype, "top_split", {
			'get' : function() { return this.top_splitter.y; },
			'set' : function(v) {
				var px = v * this.height;
				edf.rect.set_height(this.top_viewer.el, px);
				px += this.splitter_size;
				edf.rect.set_y(this.middle_viewer.el, px);
				edf.rect.set_y(this.left_viewer.el, px);
				edf.rect.set_y(this.right_viewer.el, px);
				edf.rect.set_y(this.vertical_scroll.el, px);
				px = (this.bottom_split - v) * this.height - 2 * this.splitter_size;
				edf.rect.set_height(this.middle_viewer.el, px);
				edf.rect.set_height(this.left_viewer.el, px);
				edf.rect.set_height(this.right_viewer.el, px);
				edf.rect.set_height(this.vertical_scroll.el, px);
				this.vertical_scroll.reset();
			}
		});

		Object.defineProperty(edf.table.prototype, "right_split", {
			'get' : function() { return this.right_splitter.x; },
			'set' : function(v) {
				var px = this.width - v * this.width;
				edf.rect.set_width(this.right_viewer.el, px);
				edf.rect.set_x(this.right_viewer.el, this.width - px);
				px = (v - this.left_split) * this.width - 2 * this.splitter_size;
				edf.rect.set_width(this.middle_viewer.el, px);
				edf.rect.set_width(this.top_viewer.el, px);
				edf.rect.set_width(this.bottom_viewer.el, px);
				edf.rect.set_width(this.horizontal_scroll.el, px);
				this.horizontal_scroll.reset();
			}
		});

		Object.defineProperty(edf.table.prototype, "bottom_split", {
			'get' : function() { return this.bottom_splitter.y; },
			'set' : function(v) {
				var px = this.height - v * this.height - this.splitter_size / 2;
				edf.rect.set_height(this.bottom_viewer.el, px);
				edf.rect.set_y(this.bottom_viewer.el, this.height - px);
				px = (v - this.top_split) * this.height - 2 * this.splitter_size;
				edf.rect.set_height(this.middle_viewer.el, px);
				edf.rect.set_height(this.left_viewer.el, px);
				edf.rect.set_height(this.right_viewer.el, px);
				edf.rect.set_height(this.vertical_scroll.el, px);
				this.vertical_scroll.reset();
			}
		});
	}

	{	//	statistics func

	}
}


