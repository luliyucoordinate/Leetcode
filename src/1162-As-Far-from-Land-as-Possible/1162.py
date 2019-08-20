class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        r, c = len(grid), len(grid[0])
        data = list()
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 1:
                    data.append((i, j, 0))
        
        d = [(0,1), (0,-1), (1,0), (-1,0)]
        res = 0
        while data:
            i, j, res = data.pop(0)
            for xd, yd in d:
                x, y = i + xd, j + yd
                if 0 <= x < r and 0 <= y < c and grid[x][y] == 0:
                    grid[x][y] = 1
                    data.append((x, y, res+1))
                    
        return res if res != 0 else -1