/**
 * @param {number[][]} grid
 * @return {number}
 */
var closedIsland = function(g) {
    let r = g.length, c = g[0].length, res = 2;
    let d = [0, 1, 0, -1, 0];

    let dfs = function(x, y) {
        for (let i = 0; i < 4; i++) {
            let nx = x + d[i], ny = y + d[i + 1];
            if (0 <= nx && nx < r && 0 <= ny && ny < c && g[nx][ny] == 0) {
                g[nx][ny] = res;
                dfs(nx, ny);
            }
        }
    }
    
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (g[i][j] == 0) {
                g[i][j] = res;
                dfs(i, j);
                res++;
            }
        }
    }

    let color = new Set();
    color.add(0); color.add(1);
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (i == 0 || i == r - 1) color.add(g[i][j]);
            else if (j == 0 || j == c - 1) color.add(g[i][j]);
        }
    }
    return res - color.size;
};