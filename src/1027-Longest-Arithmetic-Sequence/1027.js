var longestArithSeqLength = function(A) {
    var n = A.length, res = 0, cM = 10000;
    var idx = Array(cM + 1);
    idx.fill(-1);
    var f = Array(n);
    for (var i = 0; i < n; ++i) {
        f[i] = Array(n);
        f[i].fill(1);
    }
    
    for (var i = 0; i < n - 1; ++i) {
        for (var j = i + 1; j < n; ++j) {
            var pre = 2 * A[i] - A[j];
            if (pre >= 0 && pre <= cM && idx[pre] != -1) f[i][j] = f[idx[pre]][i] + 1;
            else f[i][j] = 2;
            res = Math.max(res, f[i][j]);
        }
        idx[A[i]] = i;
    }
    return res;
};