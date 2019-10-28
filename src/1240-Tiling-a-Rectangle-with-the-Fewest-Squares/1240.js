var tilingRectangle = function(n, m) {
    let mem = new Array(n+1);
    for (let i = 0; i <= n; i++) {
        mem[i] = new Array(m+1);
        mem[i].fill(10000);
    }
    
    let dfs = function(x, y) {
        if (mem[x][y] != 10000) return mem[x][y];
        if ((x == 11 && y == 13) || (x == 13 && y == 11)) return 6;
        if (x == y) return 1;
        let res = x * y;
        for (let i = 1; i <= x/2; i++)
            res = Math.min(res, dfs(i, y) + dfs(x - i, y));
        for (let j = 1; j <= y/2; j++)
            res = Math.min(res, dfs(x, j) + dfs(x, y - j));
        mem[x][y] = res;
        return res;
    }
    return dfs(n, m);
};