var twoSumLessThanK = function(A, K) {
    var res = -1, n = A.length;
    A.sort();
    var l = 0, r = n - 1;
    while (l < r) {
        var t = (A[l] + A[r]);
        if (t >= K) r--;
        else {
            res = Math.max(res, t);
            l++;
        }
    }
    return res;
}