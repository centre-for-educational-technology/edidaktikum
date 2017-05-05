{	//	edf.table.header_manager

	edf.table.header_manager = function() {
		this.root = {};
		this.flat = [];
		this.pos_max = 0;
	};

	edf.table.header_manager.prototype.get_group = function(group_name) {
		if (!edf.isdef(this.root[group_name])) this.root[group_name] = []
		return this.root[group_name];
	};

	edf.table.header_manager.prototype.add = function(item, group_name) {
		this.flat.push(item);
		this.get_group(group_name).push(item);	
	};

	edf.table.header_manager.prototype.rem = function(item) {
		this.flat.splice(this.flat.indexOf(item), 1);

		for (var group_name in this.root) {
			var group = this.root[group_name];

			if (group.indexOf(item) != -1) {
				group.splice(group.indexOf(item), 1);
				if (group.length < 1) delete this.root[group_name];
				return;
			}
		}

	};


	edf.table.header_manager.prototype.get_visible = function(min, max, stickies) {
		var ret = [];

		for (var group_name in this.root) {
			var group = this.root[group_name];

			for (var i = 0; i < group.length; i++) {
				var visible = group[i].test_visible(min, max);
				var sticky = (stickies === true) && group[i].sticky;
				if (visible || sticky) ret.push(group[i]);
			}
		}

		return ret;
	};

	edf.table.header_manager.prototype.calculate_positions = function(offset) {
		var pos = edf.optional(offset, 0);

		for (var group_name in this.root) {
			var group = this.root[group_name];

			for (var i = 0; i < group.length; i++) {
				group[i].pos = pos;
				pos += group[i].size;
			}
		}

		this.pos_max = pos;
	};

}

{	//	edf.table.header
	edf.table.header = function(type, name) {
		this.type = type;
		this.name = name;

		this.data = {};
		this.func = undefined;

		this.sticky = false;
		this.visible = true;
		this.visibility_version = -1;

		this.size = 0;
		this.pos = 0;

		this.rows = undefined;
		this.cols = undefined;
		this.cells = {};
	};

	edf.table.header.row_counter = 0;

	edf.table.header.create_row = function(data, size, sticky) {
		var item = new edf.table.header('row', edf.table.header.row_counter++);
		item.data = data;
		item.size = size;
		item.sticky = edf.optional(sticky, item.sticky);
		return item;
	};

	edf.table.header.create_col = function(name, size, sticky) {
		var item = new edf.table.header('col', name);
		item.size = size;
		item.sticky = edf.optional(sticky, item.sticky);
		return item;
	};

	edf.table.header.create_dynarow = function(name, func, rows, cols, size, sticky) {
		var item = new edf.table.header('dynarow', name);
		item.func = func;
		item.rows = rows;
		item.cols = cols;
		item.size = size;
		item.sticky = edf.optional(sticky, item.sticky);
		return item;
	};

	edf.table.header.create_dynacol = function(name, func, rows, cols, size, sticky) {
		var item = new edf.table.header('dynacol', name);
		item.func = func;
		item.rows = rows;
		item.cols = cols;
		item.size = size;
		item.sticky = edf.optional(sticky, item.sticky);
		return item;
	};

	edf.table.header.create_group_item = function(name) {
		var item = new edf.table.header('group_item', name);
		return item;
	}

	edf.table.header.create_colgroup = function(name) {
		var item = new edf.table.header('colgroup', name);
		item.size = 0;
		return item;
	};

	edf.table.header.create_rowgroup = function(name) {
		var item = new edf.table.header('rowgroup', name);
		item.size = 0;
		return item;
	};

	edf.table.header.prototype.test_visible = function(min, max) {	

		return this.pos < max && (this.pos + this.size) >= min;
	};

	edf.table.header.prototype.get_cell = function(col) {
		if (!edf.isdef(this.cells[col.name])) {
			var cell = new edf.table.cell(col, this);
			this.cells[col.name] = cell;
			col.cells[this.name] = cell;
		}

		//TODO: temporary fix for not removing cached cells associated with removed rows/cols which still refer to old rows/cols in case they have the same name
		var cell = this.cells[col.name];
		cell.row = this;
		cell.col = col;

		return cell;
	};

	edf.table.header.prototype.test_update_data = function(visibility_version) {
		if (this.visibility_version === visibility_version) return;
		this.update_data();
		this.visibility_version = visibility_version;
	};	

	edf.table.header.prototype.update_data = function() {
		var rows = this.rows.filter(function(item) { return item.visible && item.type == 'row' && item.sticky == false; });
		var cols = this.cols.filter(function(item) { return item.visible && item.type == 'col' && item.sticky == false; });

		if (this.type == 'dynarow') {
			for (var x = 0; x < cols.length; x++) {
				var values = [];
				for (var y = 0; y < rows.length; y++) {
					values.push(rows[y].data[cols[x].name]);
				}
				var value = this.func(values).toString();
				value = value === 'Undefined' || value === 'NaN' ? '' : value;
				this.data[cols[x].name] = {'value' : value, 'dynamic' : ''};
			}
		}

		if (this.type == 'dynacol') {
			for (var y = 0; y < rows.length; y++) {
				var values = [];
				for (var x = 0; x < cols.length; x++) {
					values.push(rows[y].data[cols[x].name]);
				}
				var value = this.func(values).toString();
				value = value === 'Undefined' || value === 'NaN' ? '' : value;
				this.data[rows[y].name]= {'value' : value, 'dynamic' : ''};
			}
		}
	};

	edf.table.header.prototype.render = function(el) {
		if (this.type === 'group_item') {
			el.setAttribute('data-group_item', this.name);
		} else {
			el.innerHTML = this.name;
			if (this.sticky) el.setAttribute("data-sticky", "");
		}		
	}
}

{	//	edf.table.cell
	edf.table.cell = function(col, row) {
		this.col = col;
		this.row = row;
	}

	edf.table.cell.prototype.render = function(el) {
		if (this.row.type == 'group_item') {
			el.setAttribute('data-group_item', this.row.name);
			return;
		}
		if (this.col.type == 'group_item') {
			el.setAttribute('data-group_item', this.col.name);
			return;
		}
		if (this.col.sticky) {
			el.setAttribute("data-sticky_col", "");
		}
		if (this.row.sticky) {
			el.setAttribute("data-sticky_row", "");
		}

		var data = this.col.type == "dynacol" ? this.col.data[this.row.name] : this.row.data[this.col.name];

		if (!edf.isdef(data)) return;
		if (data instanceof Object) {
			for (var key in data) {
				if (!edf.isdef(data[key])) continue;
				if (key == "title") el.title = data[key];
				el.setAttribute("data-" + key, data[key]);
			}
		} else {
			el.innerHTML = data;
		}
	}
}
