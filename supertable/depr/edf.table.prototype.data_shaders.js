edf.table.prototype.data_shaders = [];

edf.table.prototype.data_shaders.push({
	'title' : 'Average',
	'description' : 'description',
	'renderer' : function(data) {
		var values = data.map(function(item){return item.grade;});
		return edf.math.mean(values);
	}
});

edf.table.prototype.data_shaders.push({
	'title' : 'Median',
	'description' : 'description description',
	'renderer' : function(data) {
		var values = data.map(function(item){return item.grade;});
		return edf.math.median(values);
	}
});

edf.table.prototype.data_shaders.push({
	'title' : 'Mode',
	'description' : 'description description description description',
	'renderer' : function(data) {
		var values = data.map(function(item){return item.grade;});
		return edf.math.mode(values);
	}
});

edf.table.prototype.data_shaders.push({
	'title' : 'Standard deviation',
	'description' : 'description description',
	'renderer' : function(data) {
		var values = data.map(function(item){return item.grade;});
		return edf.math.standard_deviation(values);
	}
});

edf.table_old = edf.table;
delete edf.table;