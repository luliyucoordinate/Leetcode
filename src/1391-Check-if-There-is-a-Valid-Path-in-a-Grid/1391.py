class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        d = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        p = [[2, -1, 0, -1], 
            [-1, 3, -1, 1], 
            [-1, 2, 1, -1],
            [1, 0, -1, -1],
            [-1, -1, 3, 2],
            [3, -1, -1, 0]]

        r, c = len(grid), len(grid[0])
        def dfs(x, y, di):
            '''
            x:  横坐标
            y:  纵坐标
            di: 前一次方向
            '''
            if p[grid[x][y] - 1][di] == -1: return False
            if x == r - 1 and y == c - 1: return True

            dx, dy = d[p[grid[x][y] - 1][di]]
            nx, ny = x + dx, y + dy
            if 0 <= nx < r and 0 <= ny < c:
                if dfs(nx, ny, (p[grid[x][y] - 1][di] + 2) % 4): return True
            return False

        return dfs(0, 0, 0) or dfs(0, 0, 1) or dfs(0, 0, 2) or dfs(0, 0, 3)