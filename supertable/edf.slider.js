{	//edf.slider

	edf.slider = function(callback, horizontal, vertical) {
		this.callback = edf.optional(callback, function(){});
		this.horizontal = horizontal === true;
		this.vertical = vertical === true;
		this.x = 0;
		this.y = 0;
		this.range_x = 0;
		this.range_y = 0;
		this.enabled = true;
		this.clamp_min = 0;
		this.clamp_max = 1;
		this.clamp = true;

		var class_name = "edf_slider" + (this.horizontal ? " horizontal" : "") + (this.vertical ? " vertical" : "");
		this.el = edf.create_element("svg", class_name);
		this.thumb = edf.create_element("div", "thumb", this.el);
		new edf.drag_handler(this.thumb, "left", function(dx, dy) {
			if (!this.enabled) return;
			this.mod_px(dx, dy);
		}.bind(this));
	};

	edf.slider.prototype.refresh_range = function() {
		var bar_rect = edf.rect.get(this.el);
		var thumb_rect = edf.rect.get(this.thumb);
		this.range_x = bar_rect.width - thumb_rect.width;
		this.range_y = bar_rect.height - thumb_rect.height;
	};

	edf.slider.prototype.apply = function() {
		if (this.clamp) {
			this.x = edf.clamp(this.clamp_min, this.x, this.clamp_max);
			this.y = edf.clamp(this.clamp_min, this.y, this.clamp_max);
		}
		edf.rect.set(this.thumb, this.horizontal ? this.x * this.range_x : 0, this.vertical ? this.y * this.range_y: 0);
		this.callback(this.x, this.y);
	};

	edf.slider.prototype.reset = function() {
		this.set(this.x, this.y);
	};

	edf.slider.prototype.reset_px = function() {
		var tr = edf.rect.get(this.thumb);
		this.refresh_range();
		this.x = tr.x / this.range_x;
		this.y = tr.y / this.range_y;
		this.callback(this.x, this.y);
	};

	edf.slider.prototype.set = function(x, y) {
		this.refresh_range();
		this.x = x; 
		this.y = y;
		this.apply();
	};

	edf.slider.prototype.set_px = function(x, y) {
		this.refresh_range();
		this.x = x / this.range_x;
		this.y = y / this.range_y;
		this.apply();
	};

	edf.slider.prototype.mod_px = function(dx, dy) {
		this.refresh_range();
		this.x = (this.x * this.range_x + dx) / this.range_x;
		this.y = (this.y * this.range_y + dy) / this.range_y;
		this.apply();
	};

	edf.slider.prototype.disable = function() {
		this.enabled = false;
		this.thumb.style.cursor = "auto";
	};

	edf.slider.prototype.enable = function() {
		this.enabled = true;
		this.thumb.style.cursor = "";
	};

}

/*	{	//test

		window.addEventListener("load", function() {
			var sb = new edf.slider(function(dx, dy){console.log(dx + " " + dy);}, true, false);
			document.body.appendChild(sb.el);
			var sb2 = new edf.slider(function(dx, dy){console.log(dx + " " + dy);}, true, false);
			document.body.appendChild(sb2.el);
		});
	}
*/
