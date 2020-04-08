var longestDiverseString = function(a, b, c) {
    let dfs = function(A, B, C, a, b, c) {
        if (A < B) return dfs(B, A, C, b, a, c);
        if (B < C) return dfs(A, C, B, a, c, b);
        if (B == 0) return a.repeat(Math.min(2, A));
        
        let na = Math.min(2, A), nb = A - na + 1 >= B ? 1 : 0; 
        return a.repeat(na) + b.repeat(nb) + dfs(A - na, B - nb, C, a, b, c);
    }
    
    return dfs(a, b, c, "a", "b", "c");
};