var minTime = function(n, edges, hasApple) {
    let g = {};
    for (let edge of edges) {
        let i = edge[0], j = edge[1];
        g[i] = g[i] || [];
        g[j] = g[j] || [];
        g[i].push(j);
        g[j].push(i);
    }
    
    let vis = Array(n).fill(0);
    vis[0] = 1;
    let dfs = function(x) {
        let res = 0;
        for (let i of g[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            
            let cur = dfs(i);
            if (cur) res += cur + 2;
            else if (hasApple[i]) res += 2;
        }
        return res;
    }
    return dfs(0);
};