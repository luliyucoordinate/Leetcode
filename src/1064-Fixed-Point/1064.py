class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        l, r = 0, len(A)-1
        while l <= r:
            mid = l + r >> 1
            if A[mid] - mid == 0:
                return mid
            elif A[mid] - mid < 0:
                l = mid + 1
            else:
                r = mid - 1
        return -1