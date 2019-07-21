class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        return sum(v*(v - 1)//2 for v in collections.Counter(tuple(sorted(d)) for d in dominoes).values())