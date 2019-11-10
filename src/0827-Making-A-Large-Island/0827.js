var largestIsland = function(g) {
    let data = [0, 0], r = g.length, c = g[0].length;
    let dire = [[1, 0], [0, -1], [0, 1], [-1, 0]];
    
    let check = function(i, j) {
        return (i < 0 || j < 0 || i >= r || j >= c) ? 0 : g[i][j];
    }
    
    let dfs = function(i, j, color) {
        if (check(i, j) != 1) return 0;
        g[i][j] = color;
        let ret = 1;
        for (let d of dire) {
            ret += dfs(d[0] + i, d[1] + j, color)
        }
        return ret;
    }
    
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (g[i][j] == 1) data.push(dfs(i, j, data.length));
        }
    }
    
    let res = 0;
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (g[i][j] != 0) continue;
            let s = new Set(), tmp = 0;
            for (let d of dire) {
                let color = check(i + d[0], j + d[1]);
                if (s.has(color)) continue;
                s.add(color);
                tmp += data[color];
            }
            res = Math.max(res, tmp + 1);
        }
    }
    return res == 0 ? r * c : res;
};