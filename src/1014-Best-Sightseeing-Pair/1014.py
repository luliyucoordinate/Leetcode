class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        sell, buy = 0, float('-inf')
        for i, val in enumerate(A):
            sell = max(sell, val - i + buy)
            buy = max(buy, val + i)
        return sell