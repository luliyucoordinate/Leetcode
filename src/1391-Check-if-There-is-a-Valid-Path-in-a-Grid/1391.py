class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        r, c = len(grid), len(grid[0])
        d = [0, 1, 0, -1, 0]
        p = [[1, 0, 1, 0], 
            [0, 1, 0, 1], 
            [0, 1, 1, 0],
            [1, 1, 0, 0],
            [0, 0, 1, 1],
            [1, 0, 0, 1]]
        
        q = [[0, 0]]
        while q:
            x, y = q.pop(0)
            if x == r - 1 and y == c - 1: return True

            k, grid[x][y] = grid[x][y], 0
            for i in range(4):
                nx, ny = x + d[i], y + d[i + 1]
                if 0 <= nx < r and 0 <= ny < c and grid[nx][ny] and \
                    p[k - 1][i] and p[grid[nx][ny] - 1][i ^ 2]: # 判断前一个街道和后一个街道是否联通
                    q.append([nx, ny])
        return False