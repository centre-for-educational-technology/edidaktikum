

(function() {


	function build(tag_name, class_name, parent_element, inner_html) {
		var el = document.createElement(tag_name);
		if (class_name !== undefined) el.className = class_name;
		if (parent_element !== undefined) parent_element.appendChild(el);
		if (inner_html !== undefined) el.innerHTML = inner_html;
		return el;
	}

	function taxonomy_item(node, parent, callback_changed) {
		this.map_node_path = function(node, path) {
			this.paths[node.tid] = path.slice();
			this.paths[node.tid].push(node.tid);
			path.push(node.tid);
			
			for (var i = 0; i < node.children.length; i++) {
				this.map_node_path(node.children[i], path.slice());
			}
		}.bind(this);

		this.get_node_by_tid = function(tid) {
			for (var i = 0; i < this.node.children.length; i++) {
				if (this.node.children[i].tid == tid) return this.node.children[i];
			}
			return undefined;
		}.bind(this);

		this.select = function(node) {
			var sel_node = node;
			if (sel_node === undefined) {
				for (var i = 0; i < this.node.children.length; i++) {
					if (this.node.children[i].tid == this.el_sel.value) sel_node = this.node.children[i];
				}
			} else {
				this.el_sel.value = node.tid;
			}

			this.remove_current_child();
			if (node === undefined) {
				var old_value = this.value;					
				if (sel_node === undefined) {
					if (this.root !== this) {
						this.root._value = this.node.tid;
					} else {
						this.root._value = undefined;
					}
				} else {
					this.root._value = sel_node.tid;
				}
				this.callback_changed(this.value, old_value);
			}

			if (sel_node === undefined || sel_node.children.length == 0) return;	
			this.child = new taxonomy_item(sel_node, this, this.callback_changed);		
		}.bind(this);


		this.remove_current_child = function() {
			if (this.child === undefined) return;
			this.el.removeChild(this.el.children[this.el.children.length - 1]);
			this.child = undefined;
		}.bind(this);

		this.node = node;
		this.parent = parent;
		this.child = undefined;
		this.el = build("div", "taxonomy_item");
		this.callback_changed = callback_changed || function(value) {};
		this._value = undefined;


		Object.defineProperty(this, "value", {
			"get": function() { return this.root._value; }.bind(this),
			"set": function(v) {
				this.root._value = v;
				if (!(v in this.paths)) return;
				var path = this.paths[v];
				var ti = this;

				for (var i = 1; i < path.length; i++) {
					ti.select(ti.get_node_by_tid(path[i]));
					ti = ti.child;
				}
			}.bind(this)
		});

		if (parent === undefined) {
			this.el_del = build("div", "edf_mini_button", this.el, "❌");
			this.el_del.addEventListener("click", function() {
				this.callback_changed(undefined, this.value);
				this.el.parentElement.removeChild(this.el);
			}.bind(this));

			this.el.setAttribute("data-root", "");
			this.root = this;
		} else {
			parent.el.appendChild(this.el);
			this.root = parent.root;
		}

		this.el_sel = build("select", undefined, this.el);
		build("option", undefined, this.el_sel, "-");
		for (var i = 0; i < node.children.length; i++) {
			var opt = build("option", undefined, this.el_sel, node.children[i].name);
			opt.value = node.children[i].tid;
		}

		this.el_sel.addEventListener("change", function() { this.select(); }.bind(this));

		this.paths = {};
		this.map_node_path(node, []);
	}



	function node_list_editor(el) {

		Object.defineProperty(this, "current_item", {
			"get": function() { return this._current_item; },
			"set": function(item) {
				//	Tab
				if (this._current_item !== undefined) {
					this._current_item.el.removeAttribute("data-active");
				}

				this._current_item = item;

				if (item === undefined) {
					this.el.setAttribute("data-empty", "");
				} else {
					this.el.removeAttribute("data-empty");
					item.el.setAttribute("data-active", "");

					//	Form
					for (var i = 0; i < this.structure.length; i++) {
						var field = this.structure[i];
						switch(field.type) {
							case "text_area":
								field.el.value = item[field.name];
								break;
							case "taxonomy_list":
								field.el.innerHTML = "";
								for (var j = 0; j < item[field.name].length; j++) {
									var tx = this.add_taxonomy_item(field);
									tx.value = item[field.name][j];
								}
								break;
							case "name":
								field.el.value = item[field.name];
								break;
						}
					}
				}
			}
		});

		this.create_value = function() {
			var items = [];
			for (var i = 0; i < this.items.length; i++) {
				var r_item = this.items[i];
				var item = {};
				for (var key in r_item) {
					if (key == "el") continue;
					item[key] = r_item[key];
				}
				items.push(item);
			}
			this.output.value = JSON.stringify(items);
		}.bind(this);

		this.increment_name = function(name) {
			var biggest = 0;
			for (var i = 0; i < this.items.length; i++) {
				var item_name = this.items[i].name;
				if (item_name.indexOf(name) == 0 && item_name.length > name.length) {
					var remainder = item_name.substring(name.length);
					try {
						if (parseInt(remainder) > biggest) biggest = parseInt(remainder);
					} catch(ex){}
				}
			}
			
			return name + " " + (biggest + 1);
		}.bind(this);

		this.rem_item = function(item) {
			this.items.splice(this.items.indexOf(item), 1);
			this.el_tabber.removeChild(item.el);
		}.bind(this);

		this.add_item = function(data) {
			var item = {};
			for (var i = 0; i < this.structure.length; i++) {
				var field = this.structure[i];
				switch(field.type) {
					case "name":
						if (data !== undefined) item[field.name] = data[field.name];
						else item[field.name] = this.increment_name(field.default);
						break;
					case "text_area":
						if (data !== undefined) item[field.name] = data[field.name];
						else item[field.name] = "";
						break;
					case "taxonomy_list":
						if (data !== undefined) item[field.name] = data[field.name];
						else item[field.name] = [];
						break;
				}		
			}
			this.items.push(item);

			var el_tab = build("div", "tab", undefined, item.name);
			this.el_tabber.insertBefore(el_tab, this.el_add_tab);

			el_tab.node_list_editor_item = item;
			el_tab.addEventListener("click", function(e) {
				this.current_item = e.target.node_list_editor_item;
			}.bind(this));

			item["el"] = el_tab;
			return item;
		}.bind(this);

		this.add_text_area = function(field) {
			var el = build("div", "text_area", this.el_form);
			var el_title = build("div", "title", el, field.title);
			var el_area = build("textarea", undefined, el);
			el_area.placeholder = field.description;
			field.el = el_area;

			var changefunc = function() {
				this.current_item[field.name] = field.el.value;
				this.create_value();
			}.bind(this);
			el_area.addEventListener("keyup", changefunc);
			el_area.addEventListener("mouseup", changefunc);
		}.bind(this);

		this.add_taxonomy_item = function(field) {
			var tax_changed = function(val, old_val) {
				var idx = this.current_item[field.name].indexOf(old_val);
				if (idx != -1) {
					if (val !== undefined) this.current_item[field.name].splice(idx, 1, val);
					else this.current_item[field.name].splice(idx, 1);
				} else {
					if (val !== undefined) this.current_item[field.name].push(val);
				}
				this.create_value();
			}.bind(this);

			var tx = new taxonomy_item(field.taxonomy_tree, undefined, tax_changed);
			field.el.appendChild(tx.el);
			return tx;
		}.bind(this);

		this.add_taxonomy_list = function(field) {
			var el = build("div", "taxonomy_list", this.el_form);
			var el_title = build("div", "title", el, field.title);
			var el_taxonomies = build("div", "taxonomies", el);
			var el_add_button = build("div", "edf_mini_button", el, "➕");
			field.el = el_taxonomies;

			el_add_button.addEventListener("click", function() { this.add_taxonomy_item(field); }.bind(this) );
		}.bind(this);

		this.add_name = function(field) {
			var el = build("div", "text", this.el_form);
			var el_title = build("div", "title", el, field.title);
			var el_inp = build("input", undefined, el);
			el_inp.placeholder = field.description;
			field.el = el_inp;

			var changefunc = function() {
				this.current_item[field.name] = field.el.value;
				this.current_item.el.innerHTML = field.el.value;
				this.create_value();
			}.bind(this);
			el_inp.addEventListener("keyup", changefunc);
			el_inp.addEventListener("mouseup", changefunc);
		}.bind(this);


		this.orig = el.querySelector("input");
		this.orig.type = "hidden";

		this.output = build("input", undefined, el);
		this.output.type = "hidden";
		this.output.name = "learning_outcomes_json";
		this.output.value = "[]";

		this.structure = JSON.parse(el.getAttribute("data-node_list_editor"));
		this.el_fields = [];

		this.el = build("div", "node_list_editor", el);
		this.el.setAttribute("data-empty", "");
		this.el_tabber = build("div", "tabber", this.el);
		this.el_form = build("div", "form", this.el);

		this.items = [];
		this._current_item = undefined;
		this.form = [];

		for (var i = 0; i < this.structure.length; i++) {
			var field = this.structure[i];
			switch(field.type) {
				case "text_area":
					this.add_text_area(field);
					break;
				case "taxonomy_list":
					this.add_taxonomy_list(field);
					break;
				case "name":
					this.add_name(field);
					break;
			}
		}

		this.el_add_tab = build("div", "add tab", this.el_tabber, "Add");
		this.el_add_tab.addEventListener("click", function() {	
			this.current_item = this.add_item();
		}.bind(this));

		this.el_del = build("div", "button delete", this.el_form, "Delete");
		this.el_del.addEventListener("click", function() {
			this.rem_item(this.current_item);
			if (this.items.length > 0) this.current_item = this.items[0];
			else this.current_item = undefined;
		}.bind(this));

		var data = JSON.parse(el.getAttribute("data-node_list_data"));
		for (var i = 0; i < data.length; i++) {
			this.add_item(data[i]);
		}
		if (this.items.length > 0) this.current_item = this.items[0];
	}


	addEventListener("load", function() {

		var attributes_in_b64 = ["data-node_list_editor", "data-node_list_data"];
		var node_list_editors = document.querySelectorAll("[data-node_list_editor]");
		for (var i = 0; i < node_list_editors.length; i++) {
			var el = node_list_editors[i];

			//	decode data vars
			for (var j = 0; j < attributes_in_b64.length; j++) {
				var attr_name = attributes_in_b64[j];
				if (el.hasAttribute(attr_name)) el.setAttribute(attr_name, atob(el.getAttribute(attr_name)));
			}
			

			//	create		
			new node_list_editor(el);
		}


	});

})();