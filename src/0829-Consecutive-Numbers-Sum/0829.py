class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        res, i = 0, 1
        while i * (i - 1) < 2 * n:
            if 2*n%i == 0 and (2*n//i - i + 1) % 2 == 0:
                res += 1
            i += 1
        return res