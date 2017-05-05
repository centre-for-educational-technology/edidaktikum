{	//	edf.context_menu_item

	edf.context_menu_item = function(el_button, el_info, callback) {
		this.callback = callback;
		this.el_info = el_info;
		this.el_button = el_button;
	}

	edf.context_menu_item.prototype.generate_button = function(title) {
		this.el_button = edf.create_element("div", "button");
		this.el_button.innerHTML = title;
	}

	edf.context_menu_item.prototype.generate_info = function(description) {
		this.el_info = edf.create_element("div", "info");
		this.el_info.innerHTML = description;
	}

	edf.context_menu_item.from_title_description = function(title, description, callback) {
		var item = new edf.context_menu_item(undefined, undefined, callback);
		item.generate_button(title);
		item.generate_info(description);
		return item;
	}

}

{	//	edf.context_menu
	edf.context_menu = function(x, y, items, class_name) {
		this.el = edf.create_element("div", edf.isdef(class_name) ? class_name : "edf_context_menu");
		this.container = new edf.focus_container(x, y, this.el);
		this.items = items;

		var max_button_width = 0;
		var button_top = 0;
		var max_info_width = 0;
		var max_info_height = 0;

		//	round 1
		for (var i = 0; i < this.items.length; i++) {
			var item = this.items[i];

			this.el.appendChild(item.el_button);
			this.el.appendChild(item.el_info);

			var button_rect = edf.rect.get(item.el_button);
			max_button_width = Math.max(max_button_width, button_rect.width);

			edf.rect.set(item.el_button, 0, button_top);	
			button_top += button_rect.height + 3;

			var info_rect = edf.rect.get(item.el_info);
			max_info_width = Math.max(max_info_width, info_rect.width);
			max_info_height = Math.max(max_info_height, info_rect.height);

			item.el_button.addEventListener("mouseup", function() {
				item.callback();
				this.container.close();
			}.bind(this));
		}

		max_button_width += 5;

		//	round 2
		for (var i = 0; i < items.length; i++) {
			var item = this.items[i];
			//edf.rect.set(item.el_info, max_button_width, 0, max_info_width, max_info_height);
			edf.rect.set(item.el_info, max_button_width, 0);
		}

		/*
		this.el.style.width = (max_button_width + max_info_width) + "px";
		this.el.style.height = (Math.max(button_top, max_info_height)) + "px";
		*/
	};
}

{	//	test
	/*
	window.addEventListener("mouseup", function(e) {

		new edf.context_menu(e.clientX, e.clientY, [
			edf.context_menu_item.from_title_description("button 1", "this is stuff for button 1"),
			edf.context_menu_item.from_title_description("peanut", "i am a big ol peanut and i like to eat elephants"),
			edf.context_menu_item.from_title_description("really long name i guess", "it's supposed to be title but whatever, name is ok too. Also this description is really rather longish. blaa bla blaa blaa bla blaa blaa bla blaa blaa bla blaa blaa bla blaa blaa bla blaa blaa bla blaa blaa bla blaa blaa bla blaa blaa bla blaa blaa bla blaa blaa bla blaa blaa bla blaa"),
		]);

	});
	*/

}