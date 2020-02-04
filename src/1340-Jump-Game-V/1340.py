class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)
        def findBigger(nums):
            s, res = [], [-1] * n
            for i, v in enumerate(nums):
                while s and s[0] < i - d:
                    s.pop(0)
                while s and nums[s[-1]] < v:
                    res[s.pop()] = i
                s.append(i)
            return res
        
        rb = findBigger(arr)
        lb = [n - i - 1 if i != -1 else -1 for i in findBigger(arr[::-1])[::-1]]
        
        dp, res = [1] * n, 0
        for _, i in sorted([v, i] for i, v in enumerate(arr))[::-1]:
            if lb[i] >= 0:
                dp[i] = max(dp[i], dp[lb[i]] + 1)
            if rb[i] >= 0:
                dp[i] = max(dp[i], dp[rb[i]] + 1)
            res = max(res, dp[i])
        return res