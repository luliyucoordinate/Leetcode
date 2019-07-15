class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        res = pre_sum = 0
        seen = {}
        
        for i, h in enumerate(hours):
            pre_sum += (1 if h > 8 else -1)
            if pre_sum not in seen:
                seen[pre_sum] = i
            if pre_sum > 0:
                res = i + 1
            elif pre_sum - 1 in seen:
                res = max(res, i - seen[pre_sum - 1])
        return res