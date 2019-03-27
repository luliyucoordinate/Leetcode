class Solution:
    def isUgly(self, num: int) -> bool:
        for p in [2, 3, 5]:
            while num and num%p == 0:
                num //= p
        return num == 1