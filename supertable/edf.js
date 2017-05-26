{	//edf namespace and basic utilities 

	window['edf'] = {
		'isdef' : function(x) { return x !== undefined; },
		'optional' : function(x, def) { return edf.isdef(x) ? x : def; },
		'ifdef' : function(test, a, b) { return edf.isdef(test) ? a : b },
		'filter' : function(collection, predicate) {
			var ret = [];
			for (var i = 0; i < collection.length; i++) {
				if (predicate(collection[i])) ret.push(collection[i]);
			}
			return ret;
		},
		'elapsed' : function(title) {
			var now = Date.now();
			if (!edf.isdef(edf.elapsed.last)) { 
				if (edf.isdef(title)) console.log(title);
				edf.elapsed.last = now; 	
			} else {			
				title = edf.isdef(title) ? title + " " : "";
				console.log(title + (now - edf.elapsed.last));
				edf.elapsed.last = now;
			}
		},
		'to_number' : function(s) { return Number(s.replace(/[^0-9$.,\-]/g,'')); },
		'create_element' : function(tag_name, class_name, parent) { 
			var el = document.createElement(tag_name); 
			if (edf.isdef(class_name)) el.className = class_name; 
			if (edf.isdef(parent)) parent.appendChild(el);
			return el;
		},
		'clamp' : function(min, n, max) { return Math.min(Math.max(min, n), max); },
		'noop' : function() {},
	}
}

edf.define_array = function(definition, arr) {
	var defined = {};
	for (var i = 0; i < arr.length; i++) {
		var type_name = edf.isdef(arr[i].constructor) ? arr[i].constructor.name.toLowerCase() : 'object';
		var key = Object.keys(definition)[Object.values(definition).indexOf(type_name)];
		defined[key] = arr[i];
		delete definition[key];
	}
	return defined;
};

edf.differentiate_arrays = function(old_arr, new_arr) {
	var common = [];
	var removed = [];
	var added = [];
	
	for (var i = 0; i < old_arr.length; i++) {
		if (new_arr.indexOf(old_arr[i]) == -1) {
			removed.push(old_arr[i]);
		} else {
			common.push(old_arr[i]);
		}
	}
	
	for (var i = 0; i < new_arr.length; i++) {
		if (old_arr.indexOf(new_arr[i]) == -1) {
			added.push(new_arr[i]);
		}
	}
	
	return {'common' : common, 'removed' : removed, 'added' : added};
};


{	//	browser capabilities
	edf.browser = {};
	edf.browser.is_opera = (!!window.opr && !!opr.addons) || !!window.opera || navigator.userAgent.indexOf(' OPR/') >= 0;
	edf.browser.is_firefox = typeof InstallTrigger !== 'undefined';
	edf.browser.is_safari = /constructor/i.test(window.HTMLElement) || (function (p) { return p.toString() === "[object SafariRemoteNotification]"; })(!window['safari'] || safari.pushNotification);
	edf.browser.is_ie = /*@cc_on!@*/false || !!document.documentMode;
	edf.browser.is_edge = !edf.browser.is_ie && !!window.StyleMedia;
	edf.browser.is_chrome = !!window.chrome && !!window.chrome.webstore;
	edf.browser.is_blink = (edf.browser.is_chrome || edf.browser.is_opera) && !!window.CSS;
}


edf.compress = function(s) {
	var capital_token = '²';
	var palette = [capital_token];
	var data = [];
	for (var i = 0; i < s.length; i++) {
		var c = s.substring(i, i + 1);
		var cl = c.toLowerCase();

		if (cl != c) {
			c = cl;
			data.push(0);
		}

		var idx = palette.indexOf(c);
		if (idx == -1) {
			idx = palette.length;
			palette.push(c);
		}

		data.push(idx);
	}
	var pad = function(s) {while (s.length < 5) {s = '0' + s;} return s;};
	var bin = "";
	for (var i = 0; i < data.length; i++) {
		bin += pad(data[i].toString(2));
	}
	var encoded = "";
	for (var i = 0; i < bin.length; i += 8) {
		var b = bin.substring(i, Math.min(i + 8, bin.length));
		var n = parseInt(b, 2);
		encoded += String.fromCharCode(n);
	}
	return encoded;
};



{	//	edf.drag_handler

	/*
		generic drag handling utility
	
		constructor:
			el 			- DOM element 					- the element to click on to start the drag
			callback 	- function(delta_x, delta_y) 	- is called when mouse moves while dragging
			button 		- "left", "right", "middle" 	- determines the mouse button used for dragging
	*/

	edf.drag_handler = function (el, button, callback) {
		this.button_mask = (button == "left" ? 1 : (button == "right" ? 2 : 4));
		this.callback = callback;

		this.mousedown_handler = function(e) {
			this.safari_event_fix(e);
			if ((e.buttons & this.button_mask) != this.button_mask) return;
			this.last_clientX = e.clientX;
			this.last_clientY = e.clientY;

			document.addEventListener("mousemove", this.move_handler);
			e.preventDefault();
		}.bind(this);

		this.move_handler = function(e) {
			this.safari_event_fix(e);
			if ((e.buttons & this.button_mask) != this.button_mask) {
				document.removeEventListener("mousemove", this.move_handler);
				return;
			}
			var dx = e.clientX - this.last_clientX;
			var dy = e.clientY - this.last_clientY;
			this.last_clientX = e.clientX;
			this.last_clientY = e.clientY;

			this.callback(dx, dy);
		}.bind(this);
		
		if (edf.isdef(el)) el.addEventListener("mousedown", this.mousedown_handler);
	}

	edf.drag_handler.prototype.safari_event_fix = function(e) {
		if (!edf.browser.is_safari) return;
		switch (e.which) {
			case 0: e.buttons = 0; break;
			case 1: e.buttons = 1; break;
			case 3: e.buttons = 4; break;
			case 2: e.buttons = 2; break;
		}
	}

}

{	//edf.rect

	edf.rect = function(x, y, width, height) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	};

	Object.defineProperty(edf.rect.prototype, 'left', {
		'get' : function() { return this.x; },
		'set' : function(v) { this.x = v; }
	});
	Object.defineProperty(edf.rect.prototype, 'top', {
		'get' : function() { return this.y; },
		'set' : function(v) { this.y = v; }
	});
	Object.defineProperty(edf.rect.prototype, 'right', {
		'get' : function() { return this.x + this.width; },
	});
	Object.defineProperty(edf.rect.prototype, 'bottom', {
		'get' : function() { return this.y + this.height; },
	});



	edf.rect.regex_numbers = /(\d+\.?\d+)/g;
	edf.rect.extract_numbers = function(s) { 
		var arr = s.match(edf.rect.regex_numbers); 
		for (var i = 0; i < arr.length; i++) {
			arr[i] = parseFloat(arr[i]);
		}
		return arr;
	}
	edf.rect.extract_translate = function(s) {
		s = s.split("(")[1].split(",");
		return [parseFloat(s[0]), parseFloat(s[1])];
	}

	edf.rect.get = function(el) {
		//	if exists and/or is allowed by browser, use expando property
		if (el.edf_rect_current_values === undefined) {
			var rect = {};
			var cs = getComputedStyle(el);
			if (cs.transform.length > 10) {
				var xy = edf.rect.extract_translate(cs.transform);
				rect.x = xy[0];
				rect.y = xy[1];
			}


			if (cs.width.length > 0) {
				rect.width = parseFloat(cs.width);
				/*	need a better way to implement this, if at all
				if (cs.paddingLeft.length > 0) rect.width += parseFloat(cs.paddingLeft);
				if (cs.paddingRight.length > 0) rect.width += parseFloat(cs.paddingRight);
				if (cs.marginLeft.length > 0) rect.width += parseFloat(cs.marginLeft);
				if (cs.marginRight.length > 0) rect.width += parseFloat(cs.marginRight);
				*/
			}
			if (cs.height.length > 0) {
				rect.height = parseFloat(cs.height);
				/*
				if (cs.paddingTop.length > 0) rect.height += parseFloat(cs.paddingTop);
				if (cs.paddingBottom.length > 0) rect.height += parseFloat(cs.paddingBottom);
				if (cs.marginTop.length > 0) rect.height += parseFloat(cs.marginTop);
				if (cs.marginBottom.length > 0) rect.height += parseFloat(cs.marginBottom);
				*/
			}
			

			el.edf_rect_current_values = rect;
			return rect;
		} else {
			return el.edf_rect_current_values;
		}
	};

	edf.rect.set_x = function(el, x) {
		rect = edf.rect.get(el);
		rect.y = rect.y || 0;
		rect.x = x;
		el.style.transform = "translate(" + rect.x + "px," + rect.y + "px)";	
	};

	edf.rect.set_y = function(el, y) {
		rect = edf.rect.get(el);
		rect.x = rect.x || 0;
		rect.y = y;
		el.style.transform = "translate(" + rect.x + "px," + rect.y + "px)";	
	};

	edf.rect.set_width = function(el, width) {
		rect = edf.rect.get(el);
		rect.width = width;
		el.style.width = width + "px";
	}

	edf.rect.set_height = function(el, height) {
		rect = edf.rect.get(el);
		rect.height = height;
		el.style.height = height + "px";
	}
	
	edf.rect.set = function(el, x, y, width, height) {
		var rect = edf.rect.get(el);

		if (edf.isdef(x)) {
			rect.x = x;
			rect.y = edf.isdef(y) ? y : rect.y || 0;
			el.style.transform = "translate(" + rect.x + "px," + rect.y + "px)";
		} else if (edf.isdef(y)) {
			rect.x = rect.x || 0;
			rect.y = y;
			el.style.transform = "translate(" + rect.x + "px," + rect.y + "px)";
		}
		if (edf.isdef(width)) {
			rect.width = width;
			el.style.width = rect.width + "px";	
		}
		if (edf.isdef(height)) {
			rect.height = height;
			el.style.height = rect.height + "px";	
		}
	};

	edf.rect.set_hard = function(el, x, y, width, height) {
		el.style.transform = "translate(" + x + "px," + y + "px)";
		if (edf.isdef(width)) el.style.width = width + "px";
		if (edf.isdef(height)) el.style.height = height + "px";
	};

	edf.rect.mod = function(el, x, y, width, height) {
		var current = edf.rect.get(el);
		if (edf.isdef(x) && edf.isdef(current.x)) x += current.x;
		if (edf.isdef(y) && edf.isdef(current.y)) y += current.y;
		if (edf.isdef(width) && edf.isdef(current.width)) width += current.width;
		if (edf.isdef(height) && edf.isdef(current.height)) height += current.height;
		edf.rect.set(el, x, y, width, height);
	};
	
	
}



