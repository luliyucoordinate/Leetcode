class Solution {
    public int ways(String[] pizza, int k) {
        r = pizza.length;
        c = pizza[0].length();
        dp = new int[r][c][k];
        g = new int[r + 1][c + 1];
        
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                g[i][j] = g[i][j + 1] + g[i + 1][j] - g[i + 1][j + 1] + (pizza[i].charAt(j) == 'A' ? 1 : 0);
            }
        }
        return dfs(0, 0, k - 1);
    }
    
    private int mod = 1000000007, r, c;
    private int[][][] dp;
    private int[][] g;
    
    private int dfs(int i, int j, int k) {
        if (dp[i][j][k] != 0) return dp[i][j][k];
        if (g[i][j] == 0) return 0;
        if (k == 0) return 1;
        
        int res = 0;
        for (int x = i + 1; x < r; x++) {
            if (g[i][j] - g[x][j] > 0) res = (res + dfs(x, j, k - 1)) % mod;
        }
        for (int y = j + 1; y < c; y++) {
            if (g[i][j] - g[i][y] > 0) res = (res + dfs(i, y, k - 1)) % mod;
        }
        dp[i][j][k] = res;
        return res;
    }
}