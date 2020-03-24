class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        n = slices.size();
        k = n / 3;
        return max(cal(slices, 0, n - 1), cal(slices, 1, n));
    }
private:
    int n, k;
    
    int cal(vector<int>& nums, int l, int r) {
        int dp[2][k + 1];
        memset(dp, 0, sizeof dp);
        for (int i = l; i < r; i++) {
            for (int j = k; j > 0; j--) {
                dp[0][j] = dp[1][j];
                dp[1][j] = max(dp[1][j], dp[0][j - 1] + nums[i]);
            }
        }
        return dp[1][k];
    }
};