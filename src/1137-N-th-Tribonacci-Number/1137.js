var dict = new Map();
var tribonacci = function(n) {
    if (dict.has(n)) return dict[n];
    function tri(x) {
        var a = 0, b = 1, c = 1, k = 3;
        dict[0] = 0, dict[1] = 1, dict[2] = 1;
        while (x--) {
            var t = c;
            c = a + b + c;
            a = b, b = t;
            dict[k++] = c;
        }
    }
    tri(35);
    return dict[n];
};