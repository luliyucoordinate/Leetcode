var maxNumberOfApples = function(arr) {
    arr.sort(function sortNumber(a,b) {
	    return a - b;
	});
    var res = 0, t = 0;
    for (let i of arr) {
        t += i;
        if (t > 5000) break;
        res++;
    }
    return res;
};