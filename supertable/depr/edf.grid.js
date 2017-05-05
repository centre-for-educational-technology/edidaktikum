

{	//	edf.grid
	
	edf.grid = function(rows, cols) {
		this.el = edf.create_element("div", "edf_grid");
		this.width = 0;
		this.height = 0;
		
		this.by_row = [[]];
		this.by_col = [[]];	
		this.horizontal = [];
		this.vertical = [];
		
		for (var ii = 1; ii < cols; ii++) {(function(i) {
			this.by_col.push([]);
			this.horizontal.push(new edf.slider(function(dx, dy) {
				
			}.bind(this), true, false));
		}.bind(this))(ii);}
	}
	
	edf.grid.prototype.set_size = function(width, height) {
		
	}

}

/*
{	//test

	window.addEventListener("load", function() {
		var g = new edf.grid(4, 4);
		document.body.appendChild(g.el);
		
		
	});



}*/