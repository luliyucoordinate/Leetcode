/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */
var smallestDivisor = function(A, t) {
    let l = 1, r = 1e6, m, sum;
    while (l < r) {
        m = (l + r) >> 1, sum = 0;
        for (let i of A) sum += Math.floor((i + m - 1) / m);
        if (sum > t) l = m + 1;
        else r = m; 
    }
    return l;
};