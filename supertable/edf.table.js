{	//	edf.table

	edf.table = function() {	
		this.el = edf.create_element("div", "edf_table");
		this.el_cells_outer = edf.create_element("div", "cells_outer", this.el);
		this.el_cells_inner = edf.create_element("div", "cells_inner", this.el_cells_outer);
		this.dyna_els = {};
		this.camera = new edf.rect(0,0,0,0);
		this.last_frame = Date.now();

		this.visibility_version = 0;
		this.default_row_size = 24;
		this.default_col_size = 160;

		this.cols = new edf.table.header_manager();
		this.rows = new edf.table.header_manager();
		this.header_row = this.add_row({'data' : {}, 'sticky' : 'before', 'sorting' : true});


		this.toolbar = new edf.toolbar(this.el, [
			['menu', 'functions', 'functions'],		
			['toggle', 'fullsize', 'fullsize', function(fullsize) { 
				if (fullsize) {
					edf.rect.set_hard(this.el, this.max_rect.x, this.max_rect.y, this.max_rect.width, this.max_rect.height);
					this.set_camera(this.camera.x, this.camera.y, this.max_rect.width, this.max_rect.height - 60);
				} else {
					edf.rect.set_hard(this.el, this.normal_rect.x, this.normal_rect.y, this.normal_rect.width, this.normal_rect.height);
					setTimeout(function() {
						this.set_camera(this.camera.x, this.camera.y, this.normal_rect.width, this.normal_rect.height - 60);
					}.bind(this), 300);
				}
			}.bind(this)],
			['button', 'resize', 'resize'],
		]);	
		
		this.resize_handler = new edf.drag_handler(this.toolbar.get_item_by_title('resize').el, 'left', function(x, y) {
			edf.rect.mod(this.el, undefined, undefined, x, y);
			this.mod_camera(undefined, undefined, x, y);
		}.bind(this));
		
		this.el.addEventListener("wheel", function(e) {
			e.preventDefault();
			this.set_camera(Math.max(0, this.camera.x + e.deltaX),
							Math.max(0, this.camera.y + e.deltaY));
		}.bind(this));

		edf.rect.set(this.el, 0, 0, 940, 550);
	};

	edf.table.prototype.calc_resize_rects = function() {
		this.normal_rect = edf.rect.get(this.el);
		var bcr = this.el.getBoundingClientRect();
		this.max_rect = new edf.rect(-(bcr.left - 50), this.normal_rect.y, bcr.left + bcr.right - 100, this.normal_rect.height + 50);
	};

	edf.table.prototype.initialize = function() {
		this.cols.calculate_positions();
		this.rows.calculate_positions();
		var rect = edf.rect.get(this.el_cells_outer);
		this.set_camera(0, 0, rect.width, rect.height);
		this.calc_resize_rects();
	};

	edf.table.prototype.set_camera = function(x, y, width, height) {
		x = edf.optional(x, this.camera.x);
		y = edf.optional(y, this.camera.y);
		width = edf.optional(width, this.camera.width);
		height = edf.optional(height, this.camera.height);

		this.camera.x = Math.max(0, Math.min(x, this.cols.pos_max - width));
		this.camera.y = Math.max(0, Math.min(y, this.rows.pos_max - height));
		this.camera.width = width;
		this.camera.height = height;

		if (0 == 1) {
			var t = performance.now();
			this.update_view();
			console.log(performance.now() - t);
		} else {		
			requestAnimationFrame( this.update_view.bind(this) );
		}
	};

	edf.table.prototype.mod_camera = function(x, y, width, height) {
		if (edf.isdef(x)) x += this.camera.x;
		if (edf.isdef(y)) y += this.camera.y;
		if (edf.isdef(width)) width += this.camera.width;
		if (edf.isdef(height)) height += this.camera.height;
		this.set_camera(x, y, width, height);
	};

	edf.table.prototype.get_cells = function(rows, cols) {
		var cells = {};
		for (var y = 0; y < rows.length; y++) {
			for (var x = 0; x < cols.length; x++) {
				var cell = rows[y].get_cell(cols[x]);
				cells[cell.id] = cell;
			}
		}
		return cells;
	};

	edf.table.prototype.update_view = function() {
		//	get visible rows, cols and cells
		var cols = this.cols.get_visible(this.camera.x, this.camera.x + this.camera.width, true);
		var rows = this.rows.get_visible(this.camera.y, this.camera.y + this.camera.height, true);
	
		//	find max x
		var max_x = 0, max_x_w = 0;
		for (var i = 0; i < cols.length; i++) {
			if (cols[i].sticky == 'after') {
				max_x_w += cols[i].size;
			} else {
				max_x = Math.max(max_x, cols[i].pos);
			}
		}
		max_x += max_x_w;



		//	find max y
		var max_y = 0, max_y_w = 0;
		for (var i = 0; i < rows.length; i++) {
			if (rows[i].sticky == 'after') {
				max_y_w += rows[i].size;
			} else {
				max_y = Math.max(max_y, rows[i].pos);
			}
		}
		max_y += max_y_w;

		//	sticky rect
		var sticky_left = this.camera.x;
		var sticky_top = this.camera.y;
		var sticky_right = Math.min(sticky_left + this.camera.width, max_x);
		var sticky_bottom = Math.min(sticky_top + this.camera.height, max_y);

		//	stickies and dynamic content
		for (var i = 0; i < cols.length; i++) {
			cols[i].update_data(this.visibility_version);

			if (cols[i].sticky == 'before') {
				cols[i].pos = sticky_left;
				sticky_left += cols[i].size;
			}
			if (cols[i].sticky == 'after') {
				sticky_right -= cols[i].size;
				cols[i].pos = sticky_right;
			}
		}

		for (var i = 0; i < rows.length; i++) {
			rows[i].update_data(this.visibility_version);

			if (rows[i].sticky == 'before') {
				rows[i].pos = sticky_top;
				sticky_top += rows[i].size;
			}
			if (rows[i].sticky == 'after') {
				sticky_bottom -= rows[i].size;
				rows[i].pos = sticky_bottom;
			}
		}	


		var new_cells = this.get_cells(rows, cols);

		//	remove existing ids from new cells list and delete elements with no match
		for (var cell_id in this.dyna_els) {
			if (cell_id in new_cells) {
				delete new_cells[cell_id];
			} else {
				this.el_cells_inner.removeChild(this.dyna_els[cell_id].el);
				delete this.dyna_els[cell_id];
			}
		}

		//	assign new items to cells
		for (var cell_id in new_cells) {
			var item = new_cells[cell_id];
			var el = edf.create_element('a', 'cell', this.el_cells_inner);
			var dyna = { 'item' : item, 'el' : el, 'visibility_version' : -1};
			this.dyna_els[cell_id] = dyna;
			item.dyna = dyna;

			//	stickyness
			if (item.col.sticky !== undefined) el.setAttribute("data-sticky_col", item.col.sticky);
			if (item.row.sticky !== undefined) el.setAttribute("data-sticky_row", item.row.sticky);

			//	class
			if (item.col.css_class !== undefined) el.className += " " + item.col.css_class;
			if (item.row.css_class !== undefined) el.className += " " + item.row.css_class;

			//	data
			var cell = item.get_data();
			if (cell !== undefined) {
				if (cell instanceof Object) {
					if (edf.isdef(cell.data) && cell.data instanceof Object) {
						for (var key in cell.data) {
							if (cell.data[key] === undefined) continue;
							el.setAttribute('data-' + key, cell.data[key]);			
						}
					} else {
						el.innerHTML = cell.data;
					}
					if (edf.isdef(cell.url)) el.href = cell.url;
					if (edf.isdef(cell.tooltip)) el.title = cell.tooltip;
				} else {
					el.innerHTML = cell
				}
			}

			//	sorting stuff
			if (item.row.sorting) {
				var butt_sort_ascending = edf.create_element('div', 'sort_ascending', dyna.el);
				butt_sort_ascending.addEventListener('click', (function(dyna) {
					return function() {
						this.visibility_version++;
						this.rows.add_sorter(dyna.item.col, 'ascending');
						this.rows.sort_and_filter();
						this.update_view();
					}.bind(this);
				}.bind(this))(dyna));

				var butt_sort_descending = edf.create_element('div', 'sort_descending', dyna.el);
				butt_sort_descending.addEventListener('click', (function(dyna) {
					return function() {
						this.visibility_version++;
						this.rows.add_sorter(dyna.item.col, 'descending');
						this.rows.sort_and_filter();
						this.update_view();
					}.bind(this);
				}.bind(this))(dyna));

				var butt_sort_filter = edf.create_element('div', 'sort_filter', dyna.el);
				butt_sort_filter.setAttribute('contenteditable', '');
				butt_sort_filter.addEventListener('keyup', (function(dyna) {
					return function(e) {

						var el = e.target;
						var value = el.innerText;
						if (value.length > 0) {
							el.setAttribute("data-active", "");
						} else {
							el.removeAttribute("data-active");
						}

						this.visibility_version++;
						this.rows.add_visibility_filter(dyna.item.col, value);
						this.rows.sort_and_filter();
						this.update_view();
					}.bind(this);
				}.bind(this))(dyna));
			}
		}
		
		//	apply updated positions
		for (var cell_id in this.dyna_els) {
			var dyna = this.dyna_els[cell_id];
			if (dyna.visibility_version != this.visibility_version || dyna.item.col.sticky || dyna.item.row.sticky) {
				edf.rect.set_hard(dyna.el, dyna.item.col.pos, dyna.item.row.pos, dyna.item.col.size, dyna.item.row.size);
				dyna.visibility_version = this.visibility_version;
			}	
		}
		edf.rect.set_hard(this.el_cells_inner, -this.camera.x, -this.camera.y);
	}

	edf.table.prototype.add_row = function(row) {
		var item = new edf.table.header(row);
		item.default_size(this.default_row_size);
		return this.rows.add(item);
	};

	edf.table.prototype.add_col = function(col) {
		var item = new edf.table.header(col);
		item.default_size(this.default_col_size);
		this.header_row.data[item.id] = item.title;
		return this.cols.add(item);
	};

	edf.table.prototype.add_function = function(title, row_group_name, col_group_name, func) {
		var row, col;
		var button = edf.toolbar.item.from_definition(["toggle", title, "tooltip", function(state) {
			if (state) {
				var rows = !edf.isdef(row_group_name) ? this.rows.flat : this.rows.get_group(row_group_name);
				var cols = !edf.isdef(col_group_name) ? this.cols.flat : this.cols.get_group(col_group_name);

				row = new edf.table.header({'group' : row_group_name, 'id' : title, 'title' : title, 'func' : func, 'func_rows' : rows, 'func_cols' : cols, 'size' : this.default_row_size, 'sticky' : 'after'});
				this.rows.add(row);
				col = new edf.table.header({'group' : col_group_name, 'id' : title, 'title' : title, 'func' : func, 'func_rows' : rows, 'func_cols' : cols, 'size' : this.default_col_size, 'sticky' : 'after'});
				this.cols.add(col);

			} else {
				this.rows.rem(row);
				this.cols.rem(col);
				for (var i = 0; i < this.rows.flat.length; i++) {
					this.rows.flat[i].rem_cell(col);
				}
			}
			this.cols.calculate_positions();
			this.rows.calculate_positions();
			this.visibility_version++;
			this.update_view();
		}.bind(this)], this.toolbar);

		var tb_funcs = this.toolbar.get_item_by_title("functions");
		tb_funcs.add_child(button);
	};

	edf.table.prototype.add_rows = function(rows) {

		for (var i = 0; i < rows.length; i++) {
			this.add_row(rows[i]);
		}
	}

	edf.table.prototype.add_cols = function(cols) {
		for (var i = 0; i < cols.length; i++) {
			this.add_col(cols[i]);
		}
	}

	edf.table.prototype.sort_ascending = function(col) {
		this.rows.sort_ascending(col);

	}
}


