var stoneGameIII = function(stoneValue) {
    let n = stoneValue.length, dp = Array(3).fill(0), sum = 0;

    for (let i = n - 1; i >= 0; i--) {
        sum += stoneValue[i];
        let minv = Math.min(dp[(i + 1) % 3], dp[(i + 2) % 3]);
        minv = Math.min(minv, dp[(i + 3) % 3]);
        dp[i % 3] = sum - minv;
    }

    if (dp[0] * 2 == sum) return "Tie";
    return dp[0] * 2 > sum ? "Alice" : "Bob";
};