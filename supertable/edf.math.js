edf.math = {};

edf.math.mean = function(values) {
	var total = 0;
	for (var i = 0; i < values.length; i++) total += values[i];
	return total / values.length;
}

edf.math.mode = function(values) {
	var numeric = values.length > 0 && typeof values[0] === 'number';
	var counters = {};
	for (var i = 0; i < values.length; i++) {
		if (edf.isdef(counters[values[i]])) counters[values[i]]++;
		else counters[values[i]] = 1;
	}
	var mode = [];
	var mode_count = 1;
	for (var item in counters) {
		if (numeric) item = Number(item);
		if (counters[item] > mode_count) {
			mode_count = counters[item];
			mode = [item];
		} else if (counters[item] == mode_count) {
			mode.push(item);
		}
	}
	return mode;
}

edf.math.median = function(values) {
	values = values.slice(0);
	values.sort(function(a,b){return a-b;});
	if (values.length % 2) return values[(values.length - 1) * 0.5];
	return (values[values.length * 0.5] + values[values.length * 0.5 - 1]) * 0.5;
}

edf.math.standard_deviation = function(values) {
	var mean = edf.math.mean(values);
	var square_diffs = values.map(function(v) {
		var diff = v - mean;
		return diff * diff;
	});
	var mean_square_diff = edf.math.mean(square_diffs);
	return Math.sqrt(mean_square_diff);
}