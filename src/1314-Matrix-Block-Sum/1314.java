class Solution {
    public int[][] matrixBlockSum(int[][] mat, int K) {
        int r = mat.length, c = mat[0].length;
        int[][] pre = new int[r + 1][c + 1];
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + mat[i][j];
            }
        }
        
        int[][] res = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int r1 = Math.max(0, i - K), c1 = Math.max(0, j - K), r2 = Math.min(r, i + K + 1), c2 = Math.min(c, j + K + 1);
                res[i][j] = pre[r2][c2] - pre[r1][c2] - pre[r2][c1] + pre[r1][c1];
            }
        }
        return res;
    }
}