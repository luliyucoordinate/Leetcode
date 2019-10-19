var shortestPathLength = function(graph) {
    let n = graph.length;
    let t = (1 << n) - 1, res = 0, q = [];
    let mem = new Array(n);
    for (let i = 0; i < n; i++) {
        mem[i] = new Array(1 << n);
        mem[i].fill(0);
        q[i] = [i, 1 << i];
    }
    while (true) {
        let nq = q.length;
        for (let i = 0; i < nq; ++i) {
            let pre = q.shift();
            if (pre[1] == t) return res;
            for (let j of graph[pre[0]]) {
                let new_stat = pre[1] | 1 << j;
                if (!mem[j][new_stat]) {
                    q.push([j, new_stat]);
                    mem[j][new_stat] = 1;
                }
            }
        }
        res++;
    }
};