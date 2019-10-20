class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        dp = [1] + [0] * target
        for p in prob:
            for k in range(target, -1, -1):
                dp[k] = (dp[k - 1] if k else 0) * p + dp[k] * (1 - p)
        return dp[-1]