class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        cnt = collections.Counter(text)
        return min(cnt['b'], cnt['a'], cnt['l']//2, cnt['o']//2, cnt['n'])