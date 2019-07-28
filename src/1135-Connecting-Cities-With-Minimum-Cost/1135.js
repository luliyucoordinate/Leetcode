var minimumCost = function(N, connections) {
    if (connections.length < N - 1) return -1;
    connections.sort(function(a, b){
        return a[2] - b[2];
    });
    
    var parent = Array(N);
    for (var i = 0; i < N; ++i) parent[i] = i;
    
    function find(x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    var e = 0, res = 0, k = 0;
    while (e < N - 1) {
        var pre = connections[k++];
        var x = find(pre[0] - 1), y = find(pre[1] - 1);
        if (x != y) {
            parent[x] = y;
            e++;
            res += pre[2];
        }
    }
    return res;
};