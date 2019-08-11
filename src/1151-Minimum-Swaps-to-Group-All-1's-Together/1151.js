var minSwaps = function(data) {
    var n = data.length;
    var pre = Array(n + 1);
    pre.fill(0);
    
    for (var i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + data[i - 1];
    }
    var res = pre[n], m = pre[n];
    for (var i = m; i < n; ++i) {
        res = Math.min(res, m - (pre[i] - pre[i - m]));
    }
    return res;
};