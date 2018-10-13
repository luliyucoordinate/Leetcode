# Definition for a point.
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

from collections import defaultdict
from decimal import Decimal
class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        slopes, result = defaultdict(int), 0
        for i, point1 in enumerate(points): 
            slopes.clear()
            duplicate = 1
            for _, point2 in enumerate(points[i+1:]):
                if point1.x == point2.x and point1.y == point2.y:
                    duplicate += 1
                    continue

                slope = float('inf') if point1.x == point2.x else \
                            Decimal((point1.y - point2.y))/Decimal((point1.x - point2.x))

                slopes[slope] += 1

            if result < duplicate:
                result = duplicate

            for _, val in slopes.items():
                if val + duplicate > result:
                    result = val + duplicate

        return result
        
if __name__ == "__main__":
    points = [Point(0, 0), Point(94911151, 94911150), Point(94911152, 94911151)]
    print(Solution().maxPoints(points))
