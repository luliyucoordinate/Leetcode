class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xffffffff
        while b & mask:
            a, b = a ^ b, (a & b) << 1

        return a & mask if b > mask else a