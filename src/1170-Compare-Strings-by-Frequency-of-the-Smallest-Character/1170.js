var numSmallerByFrequency = function(queries, words) {
    function f(str) {
        var cnt = 0, minChar = '~';
        for (let c of str) {
            if (c < minChar) minChar = c, cnt = 1;
            else if (c == minChar) ++cnt;
        }
        return cnt;
    }
    
    var res = [], w = [];
    for (let word of words) {
        w.push(f(word));
    }
    w = w.sort(function sortNumber(a,b) {
	    return a - b;
	});
    
    for (var i = 0; i < queries.length; ++i) {
        var cnt = f(queries[i]), l = 0, r = w.length - 1;
        while (l < r) {
            var mid = l + r >> 1;
            if (cnt < w[mid]) r = mid;
            else l = mid + 1;
        }
        if (cnt >= w[l]) l++;
        res[i] = w.length - l;
    }
    return res;
};