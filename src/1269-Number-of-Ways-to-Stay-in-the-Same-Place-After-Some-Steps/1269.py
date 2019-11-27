class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        A, mod = [0, 1], 10**9 + 7
        for t in range(steps):
            A[1:] = [sum(A[i - 1:i + 2]) % mod for i in range(1, min(arrLen + 1, t + 3))]
        return A[1] % mod