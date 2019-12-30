class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        res, i = 1, 3
        while N % 2 == 0:
            N //= 2
            
        while i * i <= N:
            cnt = 0
            while N % i == 0:
                N //= i
                cnt += 1
            res *= cnt + 1
            i += 2
            
        return res if N == 1 else res * 2