class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        return sum([v % 2 for v in collections.Counter(s).values()]) <= k <= len(s)