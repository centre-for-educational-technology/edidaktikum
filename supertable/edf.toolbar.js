
{	//	edf.toolbar

	edf.toolbar = function (parent_el, item_definitions) {
		this.root = edf.toolbar.item.from_definition(['root', 'root', 'edf_toolbar', item_definitions], this);
		this.el = this.root.el_container;
		if (edf.isdef(parent_el)) parent_el.appendChild(this.el);
	};
	
	edf.toolbar.prototype.get_item_by_title = function(title) {
		var items = this.root.flatten(true);
		for (var i = 0; i < items.length; i++) {
			if (items[i].title == title) return items[i];
		}
		return undefined;
	};
	
}

{	//	edf.toolbar.item

	edf.toolbar.item = function(type, title, class_name, callback, children, toolbar) {
		class_name = edf.optional(class_name, '');

		this.type = type;
		this.toolbar = toolbar;
		this.callback = callback;
		this.children = [];

		this.el = edf.create_element('div', type + ' item ' + class_name);
		this.el.addEventListener('mouseup', this.click.bind(this));

		if (this.type == 'menu' || this.type == 'root') {
			this.el_container = edf.create_element('div', 'container ' + class_name)
		}
		
		if (edf.isdef(children)) {
			for (var i = 0; i < children.length; i++) this.add_child(children[i]);
		}
		
		this.title = title;
		this.toggled = false;	
	}
	
	
	edf.toolbar.item.from_definition = function(definition, toolbar) {
		var defined = edf.define_array({'type' : 'string', 'title' : 'string', 'class_name' : 'string', 'tooltip' : 'string', 'callback' : 'function', 'children' : 'array'}, definition);	
		if (edf.isdef(defined.children)) {
			for (var i = 0; i < defined.children.length; i++) {
				defined.children[i] = edf.toolbar.item.from_definition(defined.children[i], toolbar);
			}
		}
		return new edf.toolbar.item(defined.type, defined.title, defined.class_name, defined.callback, defined.children, toolbar);
	};
	
	Object.defineProperty(edf.toolbar.item.prototype, 'toggled', {
		'get' : function() {
			return this.el.hasAttribute('data-toggled');
		},
		'set' : function(toggled) {
			if (toggled) {
				this.el.setAttribute('data-toggled', '');
			} else {
				this.el.removeAttribute('data-toggled');
			}
		}
	});
	
	Object.defineProperty(edf.toolbar.item.prototype, 'title', {
		'get' : function() {
			return this.el.getAttribute("data-title");
		},
		'set' : function(v) {
			this.el.innerHTML = v;
			this.el.setAttribute("data-title", edf.optional(v, ''));
		}
	});
	
	edf.toolbar.item.prototype.add_child = function(child) {
		this.children.push(child);
		this.el_container.appendChild(child.el);
		if (child.type == 'menu') this.el_container.appendChild(child.el_container);
	};
	
	edf.toolbar.item.prototype.remove_child = function(child) {
		this.children.splice(this.children.indexOf(child), 1);
		this.el_container.removeChild(child.el);
		if (child.type == 'menu') this.el_container.removeChild(child.el_container);
	};
	
	edf.toolbar.item.prototype.flatten = function(children_only) {
		children_only = edf.optional(children_only, false);
		if (!edf.isdef(this.children)) return children_only ? [] : [this];
		
		var items = [];
		for (var i = 0; i < this.children.length; i++) {
			items = items.concat(this.children[i].flatten());
		}
		if (!children_only) items.push(this);
		return items;
	};

	edf.toolbar.item.prototype.click = function() {
		this.toggled = !this.toggled;
		if (edf.isdef(this.callback)) this.callback(this.toggled);
	};
}


{	//	test
	/*
	window.addEventListener("load", function() {
		
		var tb = new edf.toolbar('left', [
			['menu', '', 'filters', [
				['toggle', 'Mean'],
				['toggle', 'Median'],
				['toggle', 'Mode'],
				['toggle', 'SD'],
				
			]],
			
			['toggle', '', 'fullsize'],
			['button', '', 'resize'],
		]);
		
		document.body.appendChild(tb.el);
		tb.initialize();

	});
	*/
}