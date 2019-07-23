var mctFromLeafValues = function(arr) {
    var res = 0;
    var s = [Number.MAX_VALUE];
    for (let a of arr) {
        while (s[s.length - 1] <= a) {
            var cur = s.pop();
            res += Math.min(s[s.length-1], a) * cur;
        }
        s.push(a);
    }
    while (s.length > 2) {
        res += s.pop() * s[s.length - 1];
    }
    return res;
};