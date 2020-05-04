class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        res = cur = 0
        for i in range(-k, k):
            cur += cardPoints[i]
            if i >= 0:
                cur -= cardPoints[i - k]
            res = max(cur, res)    
        return res