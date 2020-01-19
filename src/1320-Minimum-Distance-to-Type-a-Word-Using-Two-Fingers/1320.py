from functools import lru_cache
class Solution:
    def minimumDistance(self, word: str) -> int:
        n, sum_dis, max_a = len(word), 0, 0
        
        @lru_cache(None)
        def dis(a, b):
            return abs(a//6 - b//6) + abs(a%6 - b%6)
        
        dp = [0] * 26
        for i in range(n - 1):
            a, c = ord(word[i]) - 65, ord(word[i + 1]) - 65
            dp[a] = max(dp[b] + dis(a, c) - dis(b, c) for b in range(26))
            max_a = max(max_a, dp[a])
            sum_dis += dis(a, c)
        return sum_dis - max_a