class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        b = minutesToTest // minutesToDie + 1
        k, n = 0, 1
        while n < buckets:
            k += 1
            n *= b
        return k