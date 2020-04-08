class Solution {
    private String dfs(int A, int B, int C, String a, String b, String c) {
        if (A < B) return dfs(B, A, C, b, a, c);
        if (B < C) return dfs(A, C, B, a, c, b);
        if (B == 0) return a.repeat(Math.min(2, A));
        
        int na = Math.min(2, A), nb = A - na + 1 >= B ? 1 : 0; 
        StringBuffer res = new StringBuffer();
        res.append(a.repeat(na));
        res.append(b.repeat(nb));
        res.append(dfs(A - na, B - nb, C, a, b, c));
        return res.toString();  
    }
    
    public String longestDiverseString(int a, int b, int c) {
        return dfs(a, b, c, "a", "b", "c");
    }
}