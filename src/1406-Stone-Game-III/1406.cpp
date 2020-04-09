class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size(); 
        int dp[3] = {};
        int sum = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            sum += stoneValue[i];
            int minv = min(dp[(i + 1) % 3], dp[(i + 2) % 3]);
            minv = min(minv, dp[(i + 3) % 3]);
            dp[i % 3] = sum - minv;
        }
        
        if (dp[0] * 2 == sum) return "Tie";
        return dp[0] * 2 > sum ? "Alice" : "Bob";
    }
};