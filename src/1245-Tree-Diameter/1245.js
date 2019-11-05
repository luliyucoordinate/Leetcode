var treeDiameter = function(edges) {
    let g = {}, res = 0;
    for (let it of edges) {
        g[it[0]] = g[it[0]] || [];
        g[it[1]] = g[it[1]] || [];
        g[it[0]].push(it[1]);
        g[it[1]].push(it[0]);
    }
    let dfs = function(cur, pre) {
        let d1 = 0, d2 = 0;
        for (let i of g[cur]) {
            if (i != pre) {
                let d = dfs(i, cur);
                if (d > d1) {
                    let tmp = d1; d1 = d; d2 = tmp;
                } else if (d > d2) d2 = d;
            }
        }
        res = Math.max(res, d1 + d2);
        return d1 + 1;
    }
    dfs(0, -1);
    return res;
};