var countOrders = function(n) {
    let res = 1, mod = 1000000007;
    
    for (let i = 1; i <= n; i++) {
        res = res * (2 * i - 1) * i % mod;
    }
    return res;
};