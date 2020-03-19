var numIslands = function(grid) {
    if (grid.length == 0) return 0;

    let r = grid.length, c = grid[0].length;
    let res = 0;
    let d = [0, 1, 0, -1, 0];

    let dfs = function(grid, x, y) {
        for (let i = 0; i < 4; i++) {
            let nx = x + d[i], ny = y + d[i + 1];
            if (0 <= nx && nx < r && 0 <= ny && ny < c && grid[nx][ny] == '1') {
                grid[nx][ny] = '0';
                dfs(grid, nx, ny);
            }
        }
    }

    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                res++;
                dfs(grid, i, j);
            }
        }
    }
    return res;
};