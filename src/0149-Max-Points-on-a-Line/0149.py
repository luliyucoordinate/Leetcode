# Definition for a point.
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        def gradient(point1, point2):
            if point1.x - point2.x == 0:
                return float('inf')
            return (point1.y - point2.y)/(point1.x - point2.x)

        result = 0
        if len(points) == 1:
            result = 1
        from collections import defaultdict
        record = defaultdict(list)
        for i, point1 in enumerate(points): 
            record = defaultdict(list)                       
            for j, point2 in enumerate(points):
                if i != j:
                    g = gradient(point1, point2)
                    if point1.x == point2.x and point1.y == point2.y:
                        
                    if point1 not in record[g]:
                        record[g].append(point1)
                    if point2 not in record[g]:
                        record[g].append(point2)
            for i in record.values():
                result = max(result, len(i))

        return result
        
if __name__ == "__main__":
    points = [Point(0, -12), Point(5, 2), Point(2, 5), Point(0, -5), Point(1, 5), Point(2, -2),
    Point(5, -4), Point(3, 4), Point(-2, 4), Point(-1, 4), Point(0, -5), Point(0, -8), Point(-2, -1), Point(0, -11), Point(0, -9)]
    print(Solution().maxPoints(points))
