class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        return functools.reduce(math.gcd, collections.Counter(deck).values()) >= 2