var shortestAlternatingPaths = function(n, red_edges, blue_edges) {
    var g0 = {};
    var g1 = {};
    for (let [i, j] of red_edges) {
        g0[i] = g0[i] || [];
        g0[i].push(j);
    }
    for (let [i, j] of blue_edges) {
        g1[i] = g1[i] || [];
        g1[i].push(j);
    }
    var g = [g0, g1], res = Array(n);
    res.fill(800);
    res[0] = 0;
    
    var q = [[0, 0, 0], [0, 1, 0]];
    var vis = new Set(["00", "01"]);
    while (q.length) {
        var pre = q.shift();
        res[pre[0]] = Math.min(res[pre[0]], pre[2]);
        var nc = 1 - pre[1];
        for (let nd of g[nc][pre[0]] || []) {
            if (!vis.has(nd + "" + nc)) {
                q.push([nd, nc, pre[2] + 1]);
                vis.add(nd + "" + nc);
            }
        }
    }
    for (var i = 0; i < n; ++i) {
        if (res[i] == 800) res[i] = -1;
    }
    return res;
};