class Solution {
    public int[] pathsWithMaxScore(List<String> b) {
        int n = b.size(), mod = 1000000007;
        int[][] d = {{0, 1}, {1, 0}, {1, 1}};
        int[][][] dp = new int[n + 1][n + 1][2];
        dp[n-1][n-1][1] = 1;
        
        for (int x = n - 1; x >= 0; x--) {
            for (int y = n - 1; y >= 0; y--) {
                if (b.get(x).charAt(y) == 'X' || b.get(x).charAt(y) == 'S')
                    continue;
                for (int[] it : d) {
                    if (dp[x][y][0] < dp[x+it[0]][y+it[1]][0]){
                        dp[x][y][0] = dp[x+it[0]][y+it[1]][0];
                        dp[x][y][1] = 0;
                    }
                        
                    if (dp[x][y][0] == dp[x+it[0]][y+it[1]][0])
                        dp[x][y][1] = (dp[x][y][1] + dp[x+it[0]][y+it[1]][1]) % mod;
                }
                dp[x][y][0] += x > 0 || y > 0 ? b.get(x).charAt(y) - '0' : 0;
            }
        }
        return new int[]{dp[0][0][1] > 0 ? dp[0][0][0] : 0, dp[0][0][1]};
    }
}