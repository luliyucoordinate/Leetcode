var numPrimeArrangements = function(n) {
    var primes = Array(n+1), st = Array(n+1);
    primes.fill(0), st.fill(0);
    var cnt = 0, MOD = 1e9 + 7;
    for (var i = 2; i <= n; ++i) {
        if (!st[i]) primes[cnt++] = i;
        for (var j = 0; primes[j] <= n/i; ++j) {
            st[primes[j]*i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    
    var res = 1;
    for (var i = 1; i <= cnt; ++i) res = res*i%MOD;
    for (var i = 1; i <= n - cnt; ++i) res = res*i%MOD;
    return res;
};