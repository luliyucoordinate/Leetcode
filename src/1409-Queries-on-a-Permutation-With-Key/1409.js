var processQueries = function(queries, m) {
    let n = queries.length;
    let N = m + n + 1;
    
    let update = function(tr, x, v) {
        for (let i = x; i < N; i += i & -i) tr[i] += v;
    }

    let prefixSum = function(tr, x) {
        let res = 0;
        for (let i = x; i > 0; i -= i & -i) res += tr[i];
        return res;
    }
    
    let pos = Array(m + 1).fill(0), tree = Array(N).fill(0);
    for (let i = 1; i <= m; i++) {
        pos[i] = n + i;
        update(tree, i + n, 1);
    }
    
    let res = [];
    for (let i of queries) {
        res.push(prefixSum(tree, pos[i] - 1));
        update(tree, pos[i], -1);
        update(tree, n, 1);
        pos[i] = n;
        n--;
    }
    return res;
};