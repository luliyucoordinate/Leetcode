var minCost = function(grid) {
    let m = grid.length, n = grid[0].length;
    let q = [[0, 0, 0]], d = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    let vis = new Array(m * n).fill(0), dist = new Array(m * n).fill(100000000);
    dist[0] = 0;

    while (q.length) {
        let t = q.shift();
        let step = t[0], x = t[1], y = t[2];
        if (vis[x * n + y]) continue;
        vis[x * n + y] = true;

        for (let i = 1; i <= 4; i++) {
            let nx = x + d[i - 1][0], ny = y + d[i - 1][1];
            let new_dist = step;
            if (grid[x][y] != i) new_dist++;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx * n + ny] > new_dist) {
                dist[nx * n + ny] = new_dist;
                if (grid[x][y] != i) q.push([dist[nx * n + ny], nx, ny]);
                else q.unshift([dist[nx * n + ny], nx, ny]);
            }
        }
    }
    return dist[m * n - 1];
};