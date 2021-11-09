

(function() {


  /**
   * Builds an element. Sets the class name if a value is provided. Appends to parent if one is provided. Sets element
   * innerHtml value, if one is provided.
   *
   * @param tag_name       Tag name passed to document.createElement()
   * @param class_name     Class name, defaults to undefined
   * @param parent_element Parent element, defaults to undefined
   * @param inner_html     Inner HTML, defaults to undefined
   * @returns any          Output from call to document.createElement()
   */
	function build(tag_name, class_name, parent_element, inner_html) {
		var el = document.createElement(tag_name);
		if (class_name !== undefined) el.className = class_name;
		if (parent_element !== undefined) parent_element.appendChild(el);
		if (inner_html !== undefined) el.innerHTML = inner_html;
		return el;
	}

  /**
   * Creates a learning outcome editor widget.
   *
   * @param el Element that has required data-node_list_editor and data-node_list_data attributes present.
   */
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
                this.fill_taxonomy_list(field)
								break;
							case "name":
								field.el.value = item[field.name];
								break;
						}
					}
				}
			}
		});

    /**
     * Goes through the structure and stores the current state data into the hidden input.
     */
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

    /**
     * Creates new name value adding an incremented value at the end.
     * Example: Learning outcome 1, Learning outcome 2 and so on.
     *
     * @param name     Name to increment.
     * @returns string Name with increment added.
     */
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

    /**
     * Removes one of the learning outcomes and deals with tabs.
     */
		this.rem_item = function(item) {
			this.items.splice(this.items.indexOf(item), 1);
			this.el_tabber.removeChild(item.el);
		}.bind(this);

    /**
     * Adds a new learning outcome and deals with UI initialisation.
     *
     * @param data     Data to get field name from.
     * @returns object Newly created learning outcome.
     */
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

    /**
     * Creates a textarea element and registers changed listeners.
     *
     * @param field Field object with data.
     */
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

    /**
     * Adds the HTML structure for competence taxonomy selection.
     * It is instantiated once and used for any of the currently selected outcome.
     * Sets the el key with the corresponding created taxonomies element to the field object.
     *
     * @param field Field object with data.
     */
    this.add_taxonomy_list = function(field) {
			var el = build("div", "taxonomy_list", this.el_form);
			build("div", "title", el, field.title);
      field.el = build("div", "taxonomies", el);
		}.bind(this);

    /**
     * Creates the structure for competence taxonomy selection.
     * Assumes that current outcome has the values and updates that data according to checked or unchecked checkboxes.
     * Adds click event listener to show/hide taxonomy term children.
     * Adds click event listener to checkboxes created for the lowest level terms to update data data stores and
     * corresponding hidden input.
     *
     * @param field Field object with data.
     */
    this.fill_taxonomy_list = function(field) {
      var callback = function(child, parent) {
        var el_li = build("li", "", parent);

        if (child.children.length > 0) {
          build("div", "parent-term", el_li, child.name)
            .addEventListener("click", function() {
              var el_direct_ul = this.parentNode.querySelector('ul.term-reference-tree-level');
              el_direct_ul.style.display = (el_direct_ul.style.display === 'none') ? 'block': 'none';
            });

          var el_ul = build("ul", "term-reference-tree-level", el_li);
          el_ul.style.display = 'none';

          child.children.forEach(function(child) {
            callback(child, el_ul);
          });
        } else {
          var el_label = build("label", "term-label", el_li)
          var el_input = build("input", "term-input", el_label);
          el_input.type = "checkbox";
          el_input.value = child.tid;
          el_input.checked = (this.current_item[field.name].indexOf(child.tid) !== -1);

          if (el_input.checked) {
            var el_parent = el_input.parentNode;

            while (el_parent && !el_parent.classList.contains('taxonomies')) {
              if (el_parent.classList.contains('term-reference-tree-level') && el_parent.style.display === 'none') {
                el_parent.style.display = 'block';
              }

              el_parent = el_parent.parentNode;
            }
          }

          el_input.addEventListener('click', function(e) {
            if (!e.target.checked) {
              this.current_item[field.name].splice(this.current_item[field.name].indexOf(e.target.value), 1);
            } else {
              this.current_item[field.name].push(e.target.value);
            }
            this.create_value();
          }.bind(this));

          var el_text = document.createTextNode(child.name)
          el_label.appendChild(el_text);
        }
      }.bind(this);

      field.taxonomy_tree.children.forEach(function(child) {
        var el_ul = build("ul", "term-reference-tree-level", field.el);

        callback(child, el_ul);
      });
    }.bind(this);

    /**
     * Creates name input and title elements for the learning outcome.
     * Registers a change callback function.
     *
     * @param field Field object with data.
     */
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

		this.el_add_tab = build("div", "add tab", this.el_tabber, Drupal.t("Add"));
		this.el_add_tab.addEventListener("click", function() {
			this.current_item = this.add_item();
		}.bind(this));

		this.el_del = build("div", "button delete", this.el_form, Drupal.t("Delete"));
		this.el_del.addEventListener("click", function() {
      if (confirm(Drupal.t("Are you sure you want to delete this learning outcome? The outcome will not be removed until the form is saved.")) !== true) {
        return;
      }

			this.rem_item(this.current_item);
			if (this.items.length > 0) this.current_item = this.items[0];
			else this.current_item = undefined;
      this.create_value();
		}.bind(this));

		var data = JSON.parse(el.getAttribute("data-node_list_data"));
		for (var i = 0; i < data.length; i++) {
			this.add_item(data[i]);
		}
		if (this.items.length > 0) this.current_item = this.items[0];

		this.create_value();
	}


	addEventListener("load", function() {

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
