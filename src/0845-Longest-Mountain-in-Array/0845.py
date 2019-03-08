class Solution:
    def longestMountain(self, A: List[int]) -> int:
        res = l = r = m = 0
        n = len(A)
        while l < n:
            while m < n - 1 and A[m] < A[m+1]:
                m += 1
            if m == l:
                l += 1
                m = r = l
                continue
            r = m
            while r < n - 1 and A[r] > A[r+1]:
                r += 1
            if m != r:
                res = max(res, r - l +1)
            l = m = r
        return res