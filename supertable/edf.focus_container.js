

{	//	edf.focus_container

	edf.focus_container = function(x, y, content, close_callback) {
		this.close_callback = close_callback;
		this.bound_close = this.close.bind(this);

		this.el = edf.create_element("div", "edf_focus_container");
		this.el.style = "position:fixed;z-index:10000;left:0;top:0;width:0;height:0";

		this.set_pos(x, y);
		this.set_content(content);

		this.open();
	};

	edf.focus_container.prototype.open = function() {
		document.body.appendChild(this.el);
		document.addEventListener("mousedown", this.bound_close);
		document.addEventListener("mousewheel", this.bound_close);
		document.addEventListener("keydown", this.bound_close);
	}

	edf.focus_container.prototype.close = function(e) {
		if (edf.isdef(e)) {
			var target = e.target;
			while (target != document.body) {
				if (target == this.el) return;
				target = target.parentElement;
			}
		}	

		document.removeEventListener("mousedown", this.bound_close);
		document.removeEventListener("mousewheel", this.bound_close);
		document.removeEventListener("keydown", this.bound_close);

		document.body.removeChild(this.el);
		if (edf.isdef(this.close_callback)) this.close_callback();
	}

	edf.focus_container.prototype.set_pos = function(x, y) {
		this.el.style.transform = "translate(" + x + "px," + y + "px)";
	};

	edf.focus_container.prototype.set_content = function(el) {
		this.el.innerHTML = "";
		if (!edf.isdef(el)) return;
		this.el.appendChild(el);
	}
}

{	//	test
	/*
	window.addEventListener("load", function() {

		var stuff = edf.create_element("div");
		stuff.style = "width:100px;height:100px;background-color:red";

		var fc = new edf.focus_container(100, 100, stuff);



	});
	*/
}