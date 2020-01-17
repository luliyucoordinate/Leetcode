var makeConnected = function(n, connections) {
    if (connections.length < n - 1) return -1;
    let parent = new Array(n);
    for (let i = 0; i < n; i++) parent[i] = i;
    
    let find = function(x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    let res = n;
    for (let it of connections) {
        let x = find(it[0]), y = find(it[1]);
        if (x != y) {
            parent[x] = y;
            res--;
        }
    }
    return res - 1;
};