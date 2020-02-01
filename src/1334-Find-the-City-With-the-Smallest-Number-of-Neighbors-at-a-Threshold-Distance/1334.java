class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] d = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) d[i][i] = 0;
                else d[i][j] = 10010;
            }
        }
        
        for (int[] it : edges) {
            d[it[0]][it[1]] = d[it[1]][it[0]] = it[2];
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        
        int smallest = 10010, res = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (d[i][j] <= distanceThreshold) ++cnt;
            }
            if (cnt <= smallest) {
                res = i;
                smallest = cnt;
            }
        }
        return res;
    }
}