var numberWays = function(hats) {
    let n = hats.length, mod = 1000000007;
    let f = [], a = [];
    for (let i = 0; i < 2; i++) {
        f[i] = Array(1024).fill(0);
    }
    f[0][0] = 1;
    
    for (let i = 1; i <= 40; i++) a[i] = [];
    for (let i = 0; i < n; i++) {
        for (let hat of hats[i]) {
            a[hat].push(i);
        }
    }
    
    for (let i = 1; i <= 40; i++) {
        for (let j = 0; j < (1 << n); j++) {
            f[i % 2][j] = f[(i - 1) % 2][j];
            for (let x of a[i]) {
                if (((j >> x) & 1) != 0) {
                    f[i % 2][j] += f[(i - 1) % 2][j ^ (1 << x)];
                    f[i % 2][j] %= mod;
                }
            }
        }
    }
    return f[0][(1 << n) - 1];
};