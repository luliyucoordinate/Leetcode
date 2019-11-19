var maxSumDivThree = function(nums) {
    let dp = [0, 0, 0];
    for (let a of nums) {
        let dp2 = dp.slice();
        for (let i of dp2) {
            dp[(i + a)%3] = Math.max(dp[(i + a)%3], i + a);
        }
    }
    return dp[0];
};