class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        n = len(A)
        for left in range(n - 2, -1, -1):
            if A[left] > A[left + 1]:
                break
        else:
            return A
        right = A.index(max(a for a in A[left + 1:] if a < A[left]), left)
        A[left], A[right] = A[right], A[left]
        return A