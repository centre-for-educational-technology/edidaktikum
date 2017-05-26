{	//	edf.table.header_manager

	edf.table.header_manager = function() {
		this.root = {};
		this.flat = [];
		this.pos_max = 0;
		this.sorters = [];
		this.visibility_filters = [];
	};

	edf.table.header_manager.prototype.get_group = function(group_name) {
		if (!edf.isdef(this.root[group_name])) this.root[group_name] = []
		return this.root[group_name];
	};

	edf.table.header_manager.prototype.add = function(item) {
		this.flat.push(item);
		this.get_group(item.group).push(item);	
		return item;
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
				var item = group[i];
				var visible = item.visible && item.in_range(min, max);
				var sticky = stickies === true && item.sticky !== undefined;
				if (visible || sticky) ret.push(group[i]);
			}
		}
		return ret;
	};

	edf.table.header_manager.prototype.calculate_positions = function() {
		var pos = 0;

		for (var group_name in this.root) {
			var group = this.root[group_name];

			for (var i = 0; i < group.length; i++) {
				if (!group[i].visible) continue;
				group[i].pos = pos;
				pos += group[i].size;
			}
		}

		this.pos_max = pos;
	};

	edf.table.header_manager.prototype.add_sorter = function(col, op) {
		for (var i = 0; i < this.sorters.length; i++) {
			if (this.sorters[i].col == col) {
				this.sorters.splice(i, 1);
			}
		}
		this.sorters.splice(0, 0, {'col' : col, 'op' : op});
		if (this.sorters.length > 3) this.sorters.pop();
	};

	edf.table.header_manager.prototype.add_visibility_filter = function(col, op) {
		for (var i = 0; i < this.visibility_filters.length; i++) {
			if (this.visibility_filters[i].col == col) {
				this.visibility_filters.splice(i, 1);
			}
		}
		this.visibility_filters.splice(0, 0, {'col' : col, 'regex' : new RegExp(op.toLowerCase())});
	};

	edf.table.header_manager.prototype.sort_and_filter = function() {
		for (var group_name in this.root) {
			var group = this.root[group_name];

			//	filter visible
			for (var i = 0; i < group.length; i++) {
				group[i].visible = true;
				if (group[i].sticky !== undefined) continue;

				for (var j = 0; j < this.visibility_filters.length; j++) {
					var regex = this.visibility_filters[j].regex;
					var value = group[i].get_cell(this.visibility_filters[j].col).get_sort_value();

					if (!regex.test(value)) {
						group[i].visible = false;
						break;
					}
				}
			}

			//	sort
			for (var group_name in this.root) {
				var group = this.root[group_name];
				group.sort(function(a, b) {
					if (a.sticky == b.sticky) {								//	if equal stickyness
						for (var i = 0; i < this.sorters.length; i++) {
							var result = 0;
							var ca = a.get_cell(this.sorters[i].col).get_sort_value();
							var cb = b.get_cell(this.sorters[i].col).get_sort_value();
								if (ca === undefined) {						//	if undefined a content sort a to a higher index
									return 1;
								} else if (cb == undefined) {				//	if undefined b content sort b to a higher index
									return -1;
								} else {									//	if defined content		
									if (this.sorters[i].op == "ascending") {
										result = ca > cb ? 1 : ca < cb ? -1 : 0;
									} else {
										result = ca > cb ? -1 : ca < cb ? 1 : 0;
									}
								}
								if (result != 0 || i == (this.sorters.length - 1)) {
									return result;							//	go to another sorter if necessary, on last sorter give up
								}
						}
					} else if (a.sticky == "before") {						//	if sticky
						return -1;											//	sort a to a lower index
					} else if (b.sticky == "before") {
						return 1;											//	sort b to a lower index
					} else if (a.sticky == "after") {
						return 1;
					} else if (b.sticky == "after") {
						return -1;
					} else {
						console.log("Did you ever hear the tragedy of Darth Plagueis the Wise? I thought not. It's not a story the Jedi would tell you. It's a Sith legend. Darth Plagueis was a Dark Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to create life... He had such a knowledge of the dark side that he could even keep the ones he cared about from dying. The dark side of the Force is a pathway to many abilities some consider to be unnatural. He became so powerful... the only thing he was afraid of was losing his power, which eventually, of course, he did. Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep. Ironic, he could save others from death, but not himself.");
					}	
				}.bind(this));
			}
		}
		this.calculate_positions();
	};

}


{	//	edf.table.header

	/*

		new row/col entry format:
		{
			'id' : 'unique id',
			'data' : 'optional data'
			'title' : 'optional row / col title',
			'group' : 'optional group name',
			'sticky' : 'before' || 'after' || optionally undefined
			'size' : optional Number
			'css_class' : optional css class name

			'func' : optional function for dynamic data display
			'func_rows' : rows relevant to func
			'func_cols' : cols relevant to func
		}

	*/


	edf.table.header = function(construct_data) {
		this.type = undefined;
		this.group = undefined;

		this.id = undefined;
		this.data = {};

		this.sticky = undefined;

		this.visible = true;
		this.visibility_version = -1;
		this.size = undefined;
		this.pos = 0;

		this.func = undefined;
		this.func_rows = undefined;
		this.func_cols = undefined;

		this.cells = {};

		if (construct_data !== undefined) {
			for (var key in construct_data) {
				this[key] = construct_data[key];
			}
		}
		if (this.id === undefined) this.id = this.title;
	};

	edf.table.header.prototype.default_size = function(size) {

		if (this.size === undefined) this.size = size;
	};

	edf.table.header.prototype.in_range = function(min, max) {	

		return this.pos < max && (this.pos + this.size) >= min;
	};

	edf.table.header.prototype.get_cell = function(col) {
		if (!edf.isdef(this.cells[col.id])) {
			this.cells[col.id] = new edf.table.cell(col, this);
		}
		return this.cells[col.id];
	};

	edf.table.header.prototype.rem_cell = function(col) {
		if (edf.isdef(this.cells[col.id])) {
			delete this.cells[col.id];
		}
	}

	edf.table.header.prototype.update_data = function(visibility_version) {
		if (this.func === undefined) return;
		if (this.visibility_version == visibility_version) return;
		this.visibility_version = visibility_version;

		var rows = this.func_rows.filter(function(item) { return item.visible && item.func === undefined});
		var cols = this.func_cols.filter(function(item) { return item.visible && item.func === undefined});
		var is_row = this.func_rows.indexOf(this) != -1;

		if (is_row) {
			for (var x = 0; x < cols.length; x++) {
				var values = [];
				for (var y = 0; y < rows.length; y++) {
					values.push(rows[y].data[cols[x].id]);
				}
				var value = this.func(values).toString();
				value = value === 'Undefined' || value === 'NaN' ? '' : value;
				this.data[cols[x].id] = {'value' : value, 'dynamic' : ''};
			}
		} else {
			for (var y = 0; y < rows.length; y++) {
				var values = [];
				for (var x = 0; x < cols.length; x++) {
					values.push(rows[y].data[cols[x].id]);
				}
				var value = this.func(values).toString();
				value = value === 'Undefined' || value === 'NaN' ? '' : value;
				rows[y].data[this.id] = {'value' : value, 'dynamic' : ''};
			}
		}
	};

}

{	//	edf.table.cell
	edf.table.cell = function(col, row) {
		this.col = col;
		this.row = row;
		this.id = col.id + '_' + row.id;
	}

	edf.table.cell.prototype.render = function(el) {
		if (this.col.sticky) {
			el.setAttribute("data-sticky_col", "");
		}
		if (this.row.sticky) {
			el.setAttribute("data-sticky_row", "");
		}

		if (edf.isdef(this.col.css_class) && el.className.indexOf(this.col.css_class) == -1) {
			el.className += " " + this.col.css_class;
		}

		if (edf.isdef(this.row.css_class) && el.className.indexOf(this.row.css_class) == -1) {
			el.className += " " + this.row.css_class;
		}



		var data = this.row.data[this.col.id];

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

	edf.table.cell.prototype.get_sort_value = function() {
		var data = this.row.data[this.col.id];

		if (edf.isdef(this.col.sort_key)) {
			data = data[this.col.sort_key];
		}

		if (typeof data == "string") {
			if (parseFloat(data).toString() == data) {
				data = parseFloat(data);
			} else {
				data = data.toLowerCase();
			}
		}

		return data;
	}
}
