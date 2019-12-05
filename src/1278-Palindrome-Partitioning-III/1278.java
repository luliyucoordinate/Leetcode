class Solution {
    public int palindromePartition(String s, int k) {
        int n = s.length();
        int[][] p = new int[n][n];
        for (int j = 1; j < n; j++) {
            for (int i = j - 1; i >= 0; i--) {
                p[i][j] = s.charAt(i) == s.charAt(j) ? 0 : 1;
                if (i + 1 < j) p[i][j] += p[i+1][j-1];
            }
        }
        
        int[][] f = new int[k+1][n];
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j] = Integer.MAX_VALUE;
            }
        }
        for (int i = 0; i < n; i++) f[1][i] = p[0][i];
        for (int i = 2; i <= k; i++) {
            for (int r = i - 1; r < n; r++) {
                for (int l = i - 2; l < r; l++) {
                    f[i][r] = Math.min(f[i][r], f[i-1][l] + p[l+1][r]);
                }
            }
        }
        return f[k][n-1];
    }
}