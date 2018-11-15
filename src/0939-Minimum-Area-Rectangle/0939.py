from collections import defaultdict
class Solution:
    def minAreaRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        n = len(points)
        nx = len(set(x for x, y in points))
        ny = len(set(y for x, y in points))
        if nx == n or ny == n:
            return 0

        columns = defaultdict(list)
        if nx > ny:
            for x, y in points:
                columns[x].append(y)
        else:
            for x, y in points:
                columns[y].append(x)

        seen, result = {}, float('inf')

        for x2 in sorted(columns):
            column = columns[x2]
            column.sort()
            for j, y2 in enumerate(column):
                for i in range(j):
                    y1 = column[i]
                    if (y1, y2) in seen:
                        result = min(result, (x2 - seen[y1,y2]) * (y2 - y1))
                    seen[y1, y2] = x2
        return result if result != float('inf') else 0
        
if __name__ == "__main__":
    points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
    print(Solution().minAreaRect(points))