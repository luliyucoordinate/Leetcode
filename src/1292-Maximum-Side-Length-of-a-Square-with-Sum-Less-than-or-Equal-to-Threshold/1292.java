class Solution {
    public int maxSideLength(int[][] A, int t) {
        int r = A.length, c = A[0].length;
        int[][] pre = new int[r+1][c+1];
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + A[i-1][j-1];
            }
        }
        
        int res = 0, l = 0;
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= c; j++) {
                while (i + l <= r && j + l <= c &&
                      (pre[i+l][j+l]-pre[i+l][j]-pre[i][j+l]+pre[i][j] <= t)) {
                    res = l++;
                }
            }
        }
        return res;
    }
}