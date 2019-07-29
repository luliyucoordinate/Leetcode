var largest1BorderedSquare = function(grid) {
    var r = grid.length, c = grid[0].length;
    var h = [], v = [];
    for (var i = 0; i < r; ++i) {
        for (var j = 0; j < c; ++j) {
            h[i] = h[i] || [];
            v[i] = v[i] || [];
            h[i][j] = 0, v[i][j] = 0;
            if (grid[i][j]) {
                h[i][j] = j == 0 ? 1 : h[i][j - 1] + 1;
                v[i][j] = i == 0 ? 1 : v[i - 1][j] + 1;
            }
        }
    }
    
    var res = 0;
    for (var i = 0; i < r; ++i) {
        for (var j = 0; j < c; ++j) {
            var s = Math.min(h[i][j], v[i][j]);
            while (s > res) {
                if (v[i][j - s + 1] >= s && h[i - s + 1][j] >= s) {
                    res = s; break;
                }
                s--;
            }
        }
    }
    return res * res;
};