var findGoodStrings = function(n, s1, s2, evil) {
    let N = 501, M = 51;
    let dp = Array(N).fill(0).map(() => Array(M).fill(0).map(() => Array(2).fill(0).map(() => Array(2).fill(0)))), ne = Array(M).fill(0);
    
    ne[0] = -1;
    for (let i = 0, j = -1; i < evil.length;) {
        while (j != -1 && evil.charAt(i) != evil.charAt(j)) j = ne[j];
        ++i; ++j;
        ne[i] = j;
    }
    
    let dfs = function(si, ei, lt, rt) {
        if (ei == evil.length) return 0;
        if (si == s1.length) return 1;
        if (dp[si][ei][lt][rt] > 0) return dp[si][ei][lt][rt];
        
        let l = lt > 0 ? s1.charCodeAt(si) : 97;
        let r = rt > 0 ? s2.charCodeAt(si) : 122;
        
        for (let i = l; i <= r; i++) {
            let t = ei;
            while (t != -1 && evil.charCodeAt(t) != i) t = ne[t];
            dp[si][ei][lt][rt] = (dp[si][ei][lt][rt] + 
                                dfs(si + 1, t + 1, lt & (i == l ? 1 : 0), rt & (i == r ? 1 : 0))) % 1000000007;
        }
        return dp[si][ei][lt][rt]; 
    }
    
    return dfs(0, 0, 1, 1);
};