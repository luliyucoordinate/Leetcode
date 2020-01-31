class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] t = new int[Math.min(m, n)];
        for (int i = 0; i < m; i++) {
            int k = Math.min(m - i, n);
            for (int j = 0; j < k; j++) {
                t[j] = mat[i + j][j];
            }
            Arrays.sort(t, 0, k);
            for (int j = 0; j <k; ++j) mat[i + j][j] = t[j];
        }
        for (int i = 1; i < n; i++) {
            int k = Math.min(m, n - i);
            for (int j = 0; j < k; j++) {
                t[j] = mat[j][i + j];
            }
            Arrays.sort(t, 0, k);
            for (int j = 0; j < k; j++) mat[j][i + j] = t[j];
        }
        return mat;
    }
}