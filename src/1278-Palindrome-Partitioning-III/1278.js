var palindromePartition = function(s, k) {
    let n = s.length;
    let p = new Array(n);
    for (let i = 0; i < n; i++) {
        p[i] = new Array(n);
        p[i].fill(0);
    }
    for (let j = 1; j < n; j++) {
        for (let i = j - 1; i >= 0; i--) {
            p[i][j] = s.charAt(i) == s.charAt(j) ? 0 : 1;
            if (i + 1 < j) p[i][j] += p[i+1][j-1];
        }
    }

    let f = new Array(k+1);
    for (let i = 0; i <= k; i++) {
        f[i] = new Array(n);
        f[i].fill(100);
    }
    for (let i = 0; i < n; i++) f[1][i] = p[0][i];
    for (let i = 2; i <= k; i++) {
        for (let r = i - 1; r < n; r++) {
            for (let l = i - 2; l < r; l++) {
                f[i][r] = Math.min(f[i][r], f[i-1][l] + p[l+1][r]);
            }
        }
    }
    return f[k][n-1];
};