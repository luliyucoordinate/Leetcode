class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        res, n = 0, len(arr1)
        for a, b in (1, 1), (1, -1), (-1, -1), (-1, 1):
            right = a * arr1[0] + b * arr2[0]
            for i in range(n):
                left = a * arr1[i] + b * arr2[i] + i
                res = max(res, left - right)
                right = min(left, right)
        return res