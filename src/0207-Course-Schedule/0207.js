var canFinish = function(n, pre) {
    var g = [], d = new Array(n), q = [], vis = new Array(n);
    d.fill(0); vis.fill(0);
    for (let it of pre) {
        g[it[1]] = g[it[1]] || [];
        g[it[1]].push(it[0]);
        d[it[0]]++;
    }
    
    for (let i = 0; i < n; i++) {
        if (d[i] == 0) {
            q.push(i);
            vis[i] == 1;
        }
    }
    
    while (q.length > 0) {
        let cur = q.shift(); n--;
        for (let i of g[cur] || []) {
            if (!vis[i] && --d[i] == 0) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return n == 0;
};