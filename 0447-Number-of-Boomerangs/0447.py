class Solution:
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        def dis(point1, point2):
            return (point1[0] - point2[0])**2 + (point1[1] - point2[1])**2

        result = 0
        for i in points:
            record = {}
            for j in points:
                if j != i:
                    distance = dis(i, j)
                    record[distance] = record.get(distance, 0) + 1

            for _, val in record.items():
                if val >= 2:
                    result += (val - 1)* val

        return result

if __name__ == "__main__":
    points = [[0,0],[1,0],[-1,0],[0,1],[0,-1]]
    print(Solution().numberOfBoomerangs(points))