var hasValidPath = function(grid) {
    let r = grid.length, c = grid[0].length;
    let d = [0, 1, 0, -1, 0];
    let p = [[1, 0, 1, 0], 
            [0, 1, 0, 1], 
            [0, 1, 1, 0],
            [1, 1, 0, 0],
            [0, 0, 1, 1],
            [1, 0, 0, 1]];

    let q = [[0, 0]];
    while (q.length) {
        let it = q.shift();
        let x = it[0], y = it[1];
        if (x == r - 1 && y == c - 1) return true;

        let k = grid[x][y];
        grid[x][y] = 0;
        for (let i = 0; i < 4; i++) {
            let nx = x + d[i], ny = y + d[i + 1];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] > 0 && 
                p[k - 1][i] == 1 && p[grid[nx][ny] - 1][i ^ 2] == 1) {
                q.push([nx, ny]);
            }
        }
    }
    return false;
};