class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if not grid:
            return -1
        r, c = len(grid), len(grid[0])
        if grid[0][0] == 1 or grid[-1][-1] == 1:
            return -1
        
        dire = [[1, 0], [-1, 0], [0, -1], [0, 1], [1, 1], [1, -1], [-1, 1], [-1, -1]]
        q = [(0, 0, 1)]
        while len(q):
            m, n, l = q.pop(0)
            if m == r-1 and n == c-1:
                return l
            for i, j in dire:
                nx, ny = m + i, n + j
                if nx >= 0 and nx < r and ny >= 0 and ny < c and not grid[nx][ny]:
                    q.append((nx, ny, l + 1))
                    grid[nx][ny] = 1

        return -1