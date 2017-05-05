{	//	edf.table

	edf.table = function() {	
		this.el = edf.create_element("div", "edf_table");
		this.el_cells_outer = edf.create_element("div", "cells_outer", this.el);
		this.el_cells_inner = edf.create_element("div", "cells_inner", this.el_cells_outer);
		this.dyna_cells = [];
		this.camera = new edf.rect(0,0,0,0);
		this.last_frame = Date.now();

		this.visibility_version = 0;
		this.default_row_size = 24;
		this.default_col_size = 50;

		this.cols = new edf.table.header_manager();
		this.rows = new edf.table.header_manager();
		this.header_row = this.add_row({}, "header", this.default_row_size, true);


		this.toolbar = new edf.toolbar(this.el, [
			['menu', 'functions', 'functions'],		
			['toggle', 'fullsize', 'fullsize', function(fullsize) { 
				if (fullsize) this.el.setAttribute('fullsize', ''); 
				else this.el.removeAttribute('fullsize'); 
				for (var i = 0; i < 500; i+= 25) {
					setTimeout(function() {
						var rect = this.el.getBoundingClientRect();
						this.set_camera(0, 0, rect.width, rect.height - 60);
					}.bind(this), i);
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
	}

	edf.table.prototype.initialize = function() {
		this.cols.calculate_positions();
		this.rows.calculate_positions();
		var rect = edf.rect.get(this.el_cells_outer);
		this.set_camera(0, 0, rect.width, rect.height);
	};

	edf.table.prototype.set_camera = function(x, y, width, height) {
		if (edf.isdef(x)) this.camera.x = x;
		if (edf.isdef(y)) this.camera.y = y;
		if (edf.isdef(width)) this.camera.width = width;
		if (edf.isdef(height)) this.camera.height = height;

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
		var cells = [];
		for (var y = 0; y < rows.length; y++) {
			if (rows[y].type == 'group_item') continue;
			for (var x = 0; x < cols.length; x++) {
				if (cols[x].type == 'group_item') continue;
				cells.push(rows[y].get_cell(cols[x]));
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
			if (!cols[i].sticky && cols[i].pos > max_x) max_x = cols[i].pos;
			if (cols[i].sticky) {
				max_x_w += cols[i].size;
			} else {
				if (cols[i].pos > max_x) max_x = cols[i].pos;
			}
		}
		max_x += max_x_w;

		//	find max y
		var max_y = 0, max_y_w = 0;
		for (var i = 0; i < rows.length; i++) {
			if (!rows[i].sticky && rows[i].pos > max_y) max_y = rows[i].pos;
			if (rows[i].sticky) {
				max_y_w += rows[i].size;
			} else {
				if (rows[i].pos > max_y) max_y = rows[i].pos;
			}
		}
		max_y += max_y_w;

		//	sticky rect
		var sticky_left = this.camera.x;
		var sticky_top = this.camera.y;
		var sticky_right = Math.min(sticky_left + this.camera.width, max_x);
		var sticky_bottom = Math.min(sticky_top + this.camera.height, max_y);

		//	update sticky col positions
		for (var i = 0; i < cols.length; i++) {
			if (cols[i].sticky) {
				if (cols[i].type === 'dynacol') {
					sticky_right -= cols[i].size;
					cols[i].pos = sticky_right;
				} else {
					cols[i].pos = sticky_left;
					sticky_left += cols[i].size;
				}
			}
		}

		//	update sticky row positions
		for (var i = 0; i < rows.length; i++) {
			if (rows[i].sticky) {
				if (rows[i].type === 'dynarow') {
					sticky_bottom -= rows[i].size;
					rows[i].pos = sticky_bottom;
				} else {
					rows[i].pos = sticky_top;
					sticky_top += rows[i].size;
				}
			}
		}	


		var cells = this.get_cells(rows, cols);



		//	update dynarow and dynacol content and sticky positions
		for (var i = 0; i < cols.length; i++) {
			if (cols[i].type === 'dynacol') cols[i].test_update_data(this.visibility_version);
		}
		for (var i = 0; i < rows.length; i++) {
			if (rows[i].type === 'dynarow') rows[i].test_update_data(this.visibility_version);
		}	

		//	remove unused cells and filter out old items
		var new_cells = cells.slice();
		for (var i = this.dyna_cells.length - 1; i >= 0; i--) {
			var idx = new_cells.indexOf(this.dyna_cells[i].item);

			if (idx == -1) {
				this.el_cells_inner.removeChild(this.dyna_cells[i].el);
				this.dyna_cells.splice(i, 1);
			} else {
				new_cells.splice(idx, 1);
			}
		}

		//	assign new items to cells
		for (var i = 0; i < new_cells.length; i++) {
			var dyna = {'item' : undefined, 'el' : edf.create_element('div', undefined, this.el_cells_inner), 'visibility_version' : -1};
			dyna.el.className = "cell";
			dyna.item = new_cells[i];
			dyna.item.dyna = dyna;
			dyna.item.render(dyna.el);
			this.dyna_cells.push(dyna);
		}
		
		//	apply updated positions
		for (var i = 0; i < cells.length; i++) {
			var dyna = cells[i].dyna;
			if (dyna.visibility_version != this.visibility_version || dyna.item.col.sticky || dyna.item.row.sticky) {
				edf.rect.set_hard(dyna.el, dyna.item.col.pos, dyna.item.row.pos, dyna.item.col.size, dyna.item.row.size);
				dyna.visibility_version = this.visibility_version;
			}	
		}

		edf.rect.set_hard(this.el_cells_inner, -this.camera.x, -this.camera.y);
	}

	edf.table.prototype.add_row = function(data, group_name, size, sticky) {
		var item = edf.table.header.create_row(data, size || this.default_row_size, sticky);
		this.rows.add(item, group_name);
		return item;
	};

	edf.table.prototype.add_col = function(name, group_name, size, sticky) {
		var item = edf.table.header.create_col(name, size || this.default_col_size, sticky);
		this.cols.add(item, group_name);
		this.header_row.data[name] = name;
		return item;
	};

	edf.table.prototype.add_dynarow = function(name, row_group_name, col_group_name, func, size, sticky) {
		var rows = !edf.isdef(row_group_name) ? this.rows.flat : this.rows.get_group(row_group_name);
		var cols = !edf.isdef(col_group_name) ? this.cols.flat : this.cols.get_group(col_group_name);
		var item = edf.table.header.create_dynarow(name, func, rows, cols, size || this.default_row_size, sticky);
		this.rows.add(item, row_group_name);
		return item;
	};

	edf.table.prototype.add_dynacol = function(name, row_group_name, col_group_name, func, size, sticky) {
		var rows = !edf.isdef(row_group_name) ? this.rows.flat : this.rows.get_group(row_group_name);
		var cols = !edf.isdef(col_group_name) ? this.cols.flat : this.cols.get_group(col_group_name);
		var item = edf.table.header.create_dynacol(name, func, rows, cols, size || this.default_col_size, sticky);
		this.cols.add(item, col_group_name);
		this.header_row.data[name] = name;
		return item;
	};

	edf.table.prototype.add_function = function(title, row_group_name, col_group_name, func) {
		var row, col;
		var button = edf.toolbar.item.from_definition(["toggle", title, "tooltip", function(state) {
			if (state) {
				row = this.add_dynarow(title, row_group_name, col_group_name, func, this.default_row_size, true);
				col = this.add_dynacol(title, row_group_name, col_group_name, func, this.default_col_size, true);
			} else {
				this.rows.rem(row);
				this.cols.rem(col);
			}
			this.cols.calculate_positions();
			this.rows.calculate_positions();
			this.visibility_version++;
			this.update_view();
		}.bind(this)], this.toolbar);

		var tb_funcs = this.toolbar.get_item_by_title("functions");
		tb_funcs.add_child(button);
	};

}


