class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        res, a, b = 0, 1, 1
        while b <= k:
            a, b = b, a + b

        while a:
            if a <= k:
                k -= a
                res += 1
            a, b = b - a, a
        return res