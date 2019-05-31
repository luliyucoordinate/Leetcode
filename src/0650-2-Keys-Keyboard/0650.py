class Solution:
    def minSteps(self, n: int) -> int:
        i, res = 2, 0
        while n > 1:
            while n % i == 0:
                res += i
                n //= i
            i += 1
        return res