class Solution:
    def maxSizeSlices(self, nums: List[int]) -> int:
        n = len(nums)
        k = n // 3
        
        def cal(l, r):
            dp = [[0] * (k + 1) for _ in range(2)]
            for i in range(l, r):
                for j in range(k, 0, -1):
                    dp[0][j] = dp[1][j]
                    dp[1][j] = max(dp[1][j], dp[0][j - 1] + nums[i])
            return dp[1][k]
        return max(cal(0, n - 1), cal(1, n))