var stoneGameII = function(piles) {
    var n = piles.length;
    for (var i = n - 2; i >= 0; --i) {
        piles[i] += piles[i + 1];
    }
    var mem = [];
    for (var i = 0; i < n; i++) {
        mem[i] = Array(n);
        mem[i].fill(Number.MAX_VALUE);
    }
    
    function dfs(i, m) {
        if (mem[i][m] != Number.MAX_VALUE) return mem[i][m];
        if (i + 2 * m >= n) return piles[i];
        var res = Number.MIN_VALUE;
        for (var x = 1; x <= 2 * m; ++x) {
            res = Math.max(res, piles[i] - dfs(i + x, Math.max(m, x)));
        }
        mem[i][m] = res;
        return res;
    }
    return dfs(0, 1);
};