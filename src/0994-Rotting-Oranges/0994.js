var orangesRotting = function(grid) {
    let r = grid.length, c = grid[0].length;
    let d = [0, 1, 0, -1, 0];
    let step = 0, cnt = 0;
    let q = [];

    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (grid[i][j] == 1) cnt++;
            else if (grid[i][j] == 2) q.push([i, j]);
        }
    }

    while (q.length) {
        if (cnt == 0) return step;

        for (let k = q.length; k > 0; k--) {
            let t = q.shift();
            let x = t[0], y = t[1];
            for (let i = 0; i < 4; i++) {
                let nx = x + d[i], ny = y + d[i + 1];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 1) {
                    cnt--;
                    q.push([nx, ny]);
                    grid[nx][ny] = 2;
                }
            }
        }
        step++;
    }

    return cnt == 0 ? step : -1;
};