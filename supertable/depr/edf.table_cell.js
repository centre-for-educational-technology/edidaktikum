{	//	edf.table_cell

	edf.table_cell = function(data) {
		this.data = data;
		this.visible = false;
		this.self_left = 0;
		this.self_top = 0;
	
		//this.row = undefined;
		//this.col = undefined;
		//this.cells = {};

		//this.rendered = undefined;

		//this.self_width
		//this.self_height
		//this.self_visible
		
	}

	Object.defineProperty(edf.table_cell.prototype, "inner_html", {
		'get' : function() {
			if (!edf.isdef(this.inner_html_cached)) this.inner_html_cached = this.renderer(this);
			return this.inner_html_cached;
		}
	});

	Object.defineProperty(edf.table_cell.prototype, "cells", {
		'get' : function() {
			Object.defineProperty(this, "cells", {'value' : []});
			return this.cells;
		},
		'set' : function(v) {
			Object.defineProperty(this, "cells", {'value' : v});
		}
	});

	Object.defineProperty(edf.table_cell.prototype, "visible", {
		'get' : function() {
			if (edf.isdef(this.col)) {
				return this.col.visible && (edf.isdef(this.row) ? this.row.visible : true);
			} else if (edf.isdef(this.row)) {
				return this.row.visible;
			}
			return this.self_visible;
		},
		'set' : function(v) {
			if (edf.isdef(this.col)) this.col.visible = v;
			if (edf.isdef(this.row)) this.row.visible = v;
			if (!edf.isdef(this.row) && !edf.isdef(this.col)) this.self_visible = v;
		}
	});

	Object.defineProperty(edf.table_cell.prototype, "left", {
		'get' : function() {
			if (edf.isdef(this.col)) return this.col.left;
			return this.self_left;
		},
		'set' : function(v) {
			if (edf.isdef(this.col)) this.col.left = v;
			this.self_left = v;
		}
	});

	Object.defineProperty(edf.table_cell.prototype, "top", {
		'get' : function() {
			if (edf.isdef(this.row)) return this.row.top;
			return this.self_top;
		},
		'set' : function(v) {
			if (edf.isdef(this.row)) this.row.top = v;
			this.self_top = v;
		}
	});

	Object.defineProperty(edf.table_cell.prototype, "width", {
		'get' : function() {
			if (edf.isdef(this.col)) return this.col.width;
			return this.self_width;
		},
		'set' : function(v) {
			if (edf.isdef(this.col)) this.col.width = v;
			this.self_width = v;
		}
	});

	Object.defineProperty(edf.table_cell.prototype, "height", {
		'get' : function() {
			if (edf.isdef(this.row)) return this.row.height;
			return this.self_height;
		},
		'set' : function(v) {
			if (edf.isdef(this.row)) this.row.height = v;
			this.self_height = v;
		}
	});

	Object.defineProperty(edf.table_cell.prototype, "right", {
		'get' : function() { return this.left + this.width; },
		'set' : function(val) { this.width = val - this.left; }
	});

	Object.defineProperty(edf.table_cell.prototype, "bottom", {
		'get' : function() { return this.top + this.height; },
		'set' : function(val) { this.height = val - this.top; }
	});

	edf.table_cell.prototype.apply_rect_horizontal = function(rect) {
		this.visible = (this.right >= rect.left && this.left <= rect.right);
		return this.visible;
	}

	edf.table_cell.prototype.apply_rect_vertical = function(rect) {
		this.visible = (this.bottom >= rect.top && this.top <= rect.bottom);
		return this.visible;
	}

	edf.table_cell.prototype.apply_rect = function(rect) {
		this.visible = this.apply_rect_vertical(rect) && this.apply_rect_horizontal(rect);
		return this.visible;
	}

}

/* {	//	test
	var cell = new edf.table_cell;
	var kek = cell.cells;
	console.log(kek);
	cell.cells.push("hai");


} */
