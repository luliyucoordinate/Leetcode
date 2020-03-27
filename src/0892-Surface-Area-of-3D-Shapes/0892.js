var surfaceArea = function(grid) {
    let res = 0, r = grid.length, c = grid[0].length;
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (grid[i][j] > 0) res += grid[i][j] * 4 + 2;
            if (i > 0) res -= Math.min(grid[i - 1][j], grid[i][j]) * 2;
            if (j > 0) res -= Math.min(grid[i][j - 1], grid[i][j]) * 2;
        }
    }
    return res;
};