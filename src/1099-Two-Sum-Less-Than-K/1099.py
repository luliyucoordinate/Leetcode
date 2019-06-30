class Solution:
    def twoSumLessThanK(self, A: List[int], K: int) -> int:
        res, n = -1, len(A)
        A.sort()
        l, r = 0, n - 1
        while l < r:
            t = A[l] + A[r]
            if t >= K:
                r -= 1
            elif t < K:
                res = max(res, t)
                l += 1
        return res