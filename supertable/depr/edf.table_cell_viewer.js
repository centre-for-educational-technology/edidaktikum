

{	//	edf.table_cell_viewer
	edf.table_cell_viewer = function(cells) {
		this.el = edf.create_element("div", "table_cell_viewer");
		this.cells = cells;
		this.last_visible_cells = [];
		this.cached_visible_cells = undefined;

		this.horizontal_master = undefined;
		this.vertical_master = undefined;

		this.visible_min = undefined;
		this.visible_max = undefined;

		this.self_internal_x = 0;
		this.self_internal_y = 0;
		this.self_internal_width = 0;
		this.self_internal_height = 0;
	};

	Object.defineProperty(edf.table_cell_viewer.prototype, "internal_x", {
		'get' : function() {
			if (edf.isdef(this.horizontal_master)) return this.horizontal_master.internal_x;
			return this.self_internal_x;
		},
		'set' : function(v) {
			if (edf.isdef(this.horizontal_master)) this.horizontal_master.internal_x = v;
			this.self_internal_x = v;
		}
	});

	Object.defineProperty(edf.table_cell_viewer.prototype, "internal_y", {
		'get' : function() {
			if (edf.isdef(this.vertical_master)) return this.vertical_master.internal_y;
			return this.self_internal_y;
		},
		'set' : function(v) {
			if (edf.isdef(this.vertical_master)) this.vertical_master.internal_y = v;
			this.self_internal_y = v;
		}
	});

	Object.defineProperty(edf.table_cell_viewer.prototype, "internal_width", {
		'get' : function() {
			if (edf.isdef(this.horizontal_master)) return this.horizontal_master.internal_width;
			return this.self_internal_width;
		},
		'set' : function(v) {
			if (edf.isdef(this.horizontal_master)) this.horizontal_master.internal_width = v;
			this.self_internal_width = v;
		}
	});

	Object.defineProperty(edf.table_cell_viewer.prototype, "internal_height", {
		'get' : function() {
			if (edf.isdef(this.vertical_master)) return this.vertical_master.internal_height;
			return this.self_internal_height;
		},
		'set' : function(v) {
			if (edf.isdef(this.vertical_master)) this.vertical_master.internal_height = v;
			this.self_internal_height = v;
		}
	});

	edf.table_cell_viewer.prototype.measure_horizontal = function() {
		this.internal_width = 0;
		for (var i = 0; i < this.cells.length; i++) {
			this.cells[i].left = this.internal_width;
			this.internal_width += this.cells[i].width;
		}
	};

	edf.table_cell_viewer.prototype.measure_vertical = function() {
		this.internal_height = 0;
		for (var i = 0; i < this.cells.length; i++) {
			this.cells[i].top = this.internal_height;
			this.internal_height += this.cells[i].height;
		}
	};

	edf.table_cell_viewer.prototype.measure = function() {
		this.measure_horizontal();
		this.measure_vertical();
	};

	edf.table_cell_viewer.prototype.get_internal_rect = function() {
		var rect = edf.rect.get(this.el);
		var x_px = this.internal_x * (this.internal_width - rect.width);
		var y_px = this.internal_y * (this.internal_height - rect.height);
		return { 'left' : x_px, 'right' : x_px + rect.width, 'top' : y_px, 'bottom' : y_px + rect.height };
	}

	edf.table_cell_viewer.prototype.cull = function() {
		var internal_rect = this.get_internal_rect();
		this.cached_visible_cells = [];
		this.visible_min = undefined;
		this.visible_max = undefined;
		for (var i = 0; i < this.cells.length; i++) {
			if (this.cells[i].apply_rect(internal_rect)) {
				this.cached_visible_cells.push(this.cells[i]);
				if (!edf.isdef(this.visible_min)) {
					this.visible_min = i;
				} else {
					this.visible_max = i;
				}
			}
		}
	};

	edf.table_cell_viewer.prototype.move_to = function(x, y) {
		this.internal_x = x; 
		this.internal_y = y;
	};

	edf.table_cell_viewer.prototype.set_size = function(width, height) {
		this.internal_width = width; 
		this.internal_height = height;
	}

	edf.table_cell_viewer.prototype.create_dyna = function() {

		return edf.create_element("div", "cell", this.el);
	};

	edf.table_cell_viewer.prototype.destory_dyna = function(el) {

		this.el.removeChild(el);
	};

	edf.table_cell_viewer.prototype.get_visible_cells_from_masters = function() {
		var cells = [];

		for (var y = this.vertical_master.visible_min; y < this.vertical_master.visible_max + 1; y++) {
			for (var x = this.horizontal_master.visible_min; x < this.horizontal_master.visible_max + 1; x++) {
				var idx = x + y * this.horizontal_master.cells.length;
				cells.push(this.cells[idx]);
			}
		}
		return cells;
	};

	edf.table_cell_viewer.prototype.get_visible_cells = function() {
		if (edf.isdef(this.cached_visible_cells)) return this.cached_visible_cells;
		if (edf.isdef(this.horizontal_master) && edf.isdef(this.vertical_master)) {
			return this.get_visible_cells_from_masters();
		}
		var cells = [];
		for (var i = 0; i < this.cells.length; i++) {
			if (this.cells[i].visible) cells.push(this.cells[i]);
		}
		return cells;
	};

	edf.table_cell_viewer.prototype.render = function() {
		var new_visible_cells = this.get_visible_cells();
		var recycled_elements = [];

		//	remove old elements
		for (var i = this.last_visible_cells.length - 1; i >= 0; i--) {
			var cell = this.last_visible_cells[i];
			if (new_visible_cells.indexOf(cell) == -1) {
				recycled_elements.push(cell.dyna_el);
				this.last_visible_cells.splice(i, 1);
				delete cell.dyna_el;
			}
		}

		//	add new elements
		var rect = edf.rect.get(this.el);
		var range_x = this.internal_width - rect.width;
		var range_y = this.internal_height - rect.height;

		for (var i = 0; i < new_visible_cells.length; i++) {
			var cell = new_visible_cells[i];
			if (this.last_visible_cells.indexOf(cell) == -1) {
				cell.dyna_el = recycled_elements.length > 0 ? recycled_elements.pop() : this.create_dyna();
				cell.dyna_el.innerHTML = cell.inner_html;
				this.last_visible_cells.push(cell);	
			}
			edf.rect.set(cell.dyna_el, cell.left - this.internal_x * range_x, cell.top - this.internal_y * range_y);
		}

		//	destroy leftovers
		for (var i = 0; i < recycled_elements.length; i++) {
			this.destory_dyna(recycled_elements[i]);
		}
	};
}



