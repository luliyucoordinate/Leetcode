class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        n = len(A)
        zeros = res = l = 0
        for r in range(n):
            zeros += 1 - A[r]
            if zeros > K:
                zeros -= 1 - A[l]
                l += 1
            res = r - l + 1
        return res