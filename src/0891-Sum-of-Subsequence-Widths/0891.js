var sumSubseqWidths = function(A) {
    A.sort((a, b) => a - b);
    let res = 0, mod = 1e9 + 7, n = A.length;
    for (let i = 0; i < n; i++) {
        res <<= 1;
        res -= A[i];
        res += A[n - i - 1];
        res %= mod;
    }
    return (res + mod)%mod;
};