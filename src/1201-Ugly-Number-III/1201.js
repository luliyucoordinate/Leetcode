/**
 * @param {number} n
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var nthUglyNumber = function(n, a, b, c) {
    function gcd(x, y) {
        while (y) {
            var t = x;
            x = y;
            y = t % y;
        }
        return x;
    }
    
    function lcm2(x, y) {
        return Math.floor(x * y / gcd(x, y));
    }
    
    function lcm3(x, y, z) {
        var res = Math.floor(x * y / gcd(x, y));
        return Math.floor(res * z / gcd(res, z));
    }
    
    function cnt(k, x, y, z) {
        return Math.floor(k/x) + Math.floor(k/y) + Math.floor(k/z) - 
            Math.floor(k/lcm2(x, y)) - Math.floor(k/lcm2(x, z)) - 
            Math.floor(k/lcm2(y, z)) + Math.floor(k/lcm3(x, y, z));
    }
    
    var l = 1, r = 2000000000;
    while (l < r) {
        var mid = Math.floor((l + r)/2);
        if (cnt(mid, a, b, c) < n) l = mid + 1;
        else r = mid;
    }
    return l;
};