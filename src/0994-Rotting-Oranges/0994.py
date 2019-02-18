class Solution:
    def orangesRotting(self, grid: 'List[List[int]]') -> 'int':
        r, c = len(grid), len(grid[0])
        rot = list()
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 2:
                    rot.append((i, j, 0))
        
        d = [(0,1), (0,-1), (1,0), (-1,0)]
        res = 0
        while rot:
            i, j, res = rot.pop(0)
            for xd, yd in d:
                x = i + xd
                y = j + yd
                if 0 <= x < r and 0 <= y < c and grid[x][y] == 1:
                    grid[x][y] = 2
                    rot.append((x, y, res+1))
            
        if any(1 in row for row in grid):
            return -1
        return res