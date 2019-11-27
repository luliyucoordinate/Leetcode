var countServers = function(grid) {
    let m = grid.length, n = grid[0].length, res = 0;
    let r = new Array(m), c = new Array(n);
    r.fill(0), c.fill(0);
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j]) {
                r[i]++; c[j]++;
            }
        }
    }
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] && (r[i] + c[j] > 2)) 
                res++;
        }
    }
    return res;
};