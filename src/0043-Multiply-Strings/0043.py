class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        res, m, n = 0, len(num1), len(num2)
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                res += int(num1[-i]) * int(num2[-j]) * 10 ** (i + j - 2)
        return str(res)