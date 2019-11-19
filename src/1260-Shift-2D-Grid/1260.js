var shiftGrid = function(grid, k) {
    let n = grid.length, m = grid[0].length;
    let res = new Array(n);
    for (let i = 0; i < n; i++) {
        res[i] = new Array(m);
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            let t = j + k;
            res[(i + Math.floor(t/m))%n][t % m] = grid[i][j];
        }
    }
    return res;
};