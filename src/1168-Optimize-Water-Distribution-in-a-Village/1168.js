var minCostToSupplyWater = function(n, wells, pipes) {
    for (var i = 0; i < wells.length; ++i) {
        pipes.push([0, i+1, wells[i]]);
    }
    
    pipes.sort(function(a, b){
        return a[2] - b[2];
    });
    
    var parent = Array(n + 1);
    for (var i = 0; i <= n; ++i) parent[i] = i;
    
    function find(x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    var e = 0, res = 0, k = 0;
    while (e < n) {
        var pre = pipes[k++];
        var x = find(pre[0]), y = find(pre[1]);
        if (x != y) {
            parent[x] = y;
            e++;
            res += pre[2];
        }
    }
    return res;
};