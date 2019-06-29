class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        n = len(A)
        mem = [0] * (n + 1)
        for i in range(1, n + 1):
            cur = 0
            for j in range(1, K + 1):
                if i >= j:
                    cur = max(cur, A[i - j])
                    mem[i] = max(mem[i], mem[i - j] + cur * j)
        return mem[n]