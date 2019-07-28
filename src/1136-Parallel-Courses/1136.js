var minimumSemesters = function(N, relations) {
    var g = Array(N);
    var degrees = Array(N);
    degrees.fill(0);
    for (let [i, j] of relations) {
        i--;
        g[i] = g[i] || [];
        g[i].push(--j);
        degrees[j]++;
    }
    
    var num = 0, res = 0;
    var q = Array();
    for (var i = 0; i < N; ++i) {
        if (degrees[i] == 0) {
            num++;
            q.push(i);
        }
    }
    
    while (q.length > 0) {
        var n = q.length;
        while (n--) {
            var v = q.shift();
            for (let w of g[v] || []) {
                degrees[w]--;
                if (degrees[w] == 0) {
                    q.push(w);
                    num++;
                }
            }
        }
        res++;
    }
    return num == N ? res : -1;
};