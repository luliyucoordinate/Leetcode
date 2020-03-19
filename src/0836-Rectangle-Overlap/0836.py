class Solution:
    def isRectangleOverlap(self, r1: List[int], r2: List[int]) -> bool:
        return r1[0] < r2[2] and r1[1] < r2[3] and r1[2] > r2[0] and r1[3] > r2[1]