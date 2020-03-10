var frogPosition = function(n, edges, t, target) {
    if (n == 1) return 1.0;
    
    let g = [];
    for (let i = 0; i <= n; i++) g[i] = [];
    for (let it of edges) {
        g[it[0]].push(it[1]);
        g[it[1]].push(it[0]);
    }
    
    let dfs = function(fa, cur, tt) {
        if (cur != 1 && g[cur].length == 1 || tt == 0) {
            return cur == target;
        }
        
        let res = 0;
        for (let i of g[cur]) {
            if (i != fa) res = Math.max(res, dfs(cur, i, tt - 1));
        }
        return res / (g[cur].length - (cur != 1));
    }
    
    return dfs(-1, 1, t);
};