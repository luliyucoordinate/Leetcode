class Solution:
    def missingNumber(self, A: List[int]) -> int:
        return (A[0] + A[-1]) * (len(A) + 1) // 2 - sum(A)