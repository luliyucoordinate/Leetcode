var getMaximumGold = function(grid) {
    let m = grid.length, n = grid[0].length, res = 0;
    let d = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    
    let dfs = function(x, y) {
        let res = 0, src = grid[x][y];
        grid[x][y] = 0;
        for (let [i, j] of d) {
            let nx = x + i, ny = y + j;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny]) {
                res = Math.max(res, dfs(nx, ny) + grid[nx][ny]);
            }
        }
        grid[x][y] = src;
        return res;
    }
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j]) res = Math.max(res, dfs(i, j) + grid[i][j]);
        }
    }
    return res;
};