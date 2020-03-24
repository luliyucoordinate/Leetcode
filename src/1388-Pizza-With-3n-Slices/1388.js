var maxSizeSlices = function(nums) {
    let n = nums.length;
    let k = Math.floor(n / 3);
    
    let cal = function(l, r) {
        let dp = [];
        for (let i = 0; i < 2; i++) dp[i] = new Array(k + 1).fill(0);
        for (let i = l; i < r; i++) {
            for (let j = k; j > 0; j--) {
                dp[0][j] = dp[1][j];
                dp[1][j] = Math.max(dp[1][j], dp[0][j - 1] + nums[i]);
            }
        }
        return dp[1][k];
    }
    return Math.max(cal(0, n - 1), cal(1, n));
};