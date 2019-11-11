var closedIsland = function(g) {
    let r = g.length, c = g[0].length, res = 2;
    let dire = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    let check = function(i, j) {
        return (i < 0 || j < 0 || i >= g.length || j >= g[0].length) ? 0 : 1;
    }
    let dfs = function(i, j, color) {
        if (check(i, j, g) == 0 || g[i][j] != 0) return;
        g[i][j] = color;
        for (let d of dire) {
            dfs(d[0] + i, d[1] + j, color, g);
        }
    }
    
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (g[i][j] == 0) {
                dfs(i, j, res++, g);
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