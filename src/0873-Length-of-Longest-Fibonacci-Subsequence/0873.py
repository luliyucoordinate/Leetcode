class Solution:
    def lenLongestFibSubseq(self, A: List[int]) -> int:
        A_s = set(A)
        n = len(A)
        res = 0
        for i in range(n):
            for j in range(i+1, n):
                x, y = A[j], A[i] + A[j]
                l = 2
                if x*(res - 2) > A[-1]:
                    break
                while y in A_s:
                    x, y = y, x+y
                    l += 1
                res = max(res, l)
        return res if res >= 3 else 0