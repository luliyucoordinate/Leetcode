class Solution {
    public int minFallingPathSum(int[][] A) {
        int r = A.length, c = A[0].length;
        for (int i = r - 1; i > 0; i--) {
            int[] m1 = new int[]{20000, 0};
            int[] m2 = new int[]{20000, 0};
            for (int k = 0; k < c; k++) {
                if (A[i][k] < m1[0]) {
                    m2 = m1.clone();
                    m1[0] = A[i][k];
                    m1[1] = k;
                } else if (A[i][k] < m2[0]) {
                    m2[0] = A[i][k];
                    m2[1] = k;
                }
            }
            
            for (int j = 0; j < c; j++) {
                A[i-1][j] += (j != m1[1] ? m1[0] : m2[0]);
            }
        }
        
        int res = 20000;
        for (int i = 0; i < c; i++) {
            res = Math.min(res, A[0][i]);
        }
        return res;
    }
}