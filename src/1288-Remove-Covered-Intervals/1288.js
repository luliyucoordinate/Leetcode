/**
 * @param {number[][]} intervals
 * @return {number}
 */
var removeCoveredIntervals = function(A) {
    let res = 0, r = 0;
    A.sort((a, b) => a[0] != b[0] ? a[0] - b[0] : b[1] - a[1]);
    for (let v of A) {
        if (v[1] > r) res++;
        r = Math.max(r, v[1]);
    }
    return res;
};