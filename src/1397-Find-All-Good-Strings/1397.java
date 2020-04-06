class Solution {
    public int findGoodStrings(int n, String s1, String s2, String evil) {
        ne = new int[M];
        dp = new int[N][M][2][2];
        ne[0] = -1;
        
        for (int i = 0, j = -1; i < evil.length();) {
            while (j != -1 && evil.charAt(i) != evil.charAt(j)) j = ne[j];
            ++i; ++j;
            ne[i] = j;
        }
        return dfs(s1, s2, evil, 0, 0, 1, 1);
    }
    
    private int N = 501, M = 51;
    private int[][][][] dp;
    private int[] ne;
    
    private int dfs(String s1, String s2, String evil, int si, int ei, int lt, int rt) {
        if (ei == evil.length()) return 0;
        if (si == s1.length()) return 1;
        if (dp[si][ei][lt][rt] > 0) return dp[si][ei][lt][rt];
        
        char l = lt > 0 ? s1.charAt(si) : 'a';
        char r = rt > 0 ? s2.charAt(si) : 'z';
        
        for (char i = l; i <= r; i++) {
            int t = ei;
            while (t != -1 && evil.charAt(t) != i) t = ne[t];
            dp[si][ei][lt][rt] = (dp[si][ei][lt][rt] + 
                                dfs(s1, s2, evil, si + 1, t + 1, lt & (i == l ? 1 : 0), rt & (i == r ? 1 : 0))) % 1000000007;
        }
        return dp[si][ei][lt][rt]; 
    }
}