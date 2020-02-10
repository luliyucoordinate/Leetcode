class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cnt1, cnt2 = map(collections.Counter, (s, t))
        return sum((cnt1 - cnt2).values())