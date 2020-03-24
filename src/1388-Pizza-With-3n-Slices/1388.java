class Solution {
    public int maxSizeSlices(int[] slices) {
        n = slices.length;
        k = n / 3;
        return Math.max(cal(slices, 0, n - 1), cal(slices, 1, n));
    }
    
    private int n, k;
    
    private int cal(int[] nums, int l, int r) {
        int[][] dp = new int[2][k + 1];
        for (int i = l; i < r; i++) {
            for (int j = k; j > 0; j--) {
                dp[0][j] = dp[1][j];
                dp[1][j] = Math.max(dp[1][j], dp[0][j - 1] + nums[i]);
            }
        }
        return dp[1][k];
    }
}