class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        r, c = len(grid), len(grid[0])
        h, v = [a[:] for a in grid], [a[:] for a in grid]
        for i in range(r):
            for j in range(c):
                if grid[i][j]:
                    if i:
                        v[i][j] = v[i-1][j] + 1
                    if j:
                        h[i][j] = h[i][j-1] + 1

        res = 0
        for i in range(r):
            for j in range(c):
                if grid[i][j]:
                    s = min(h[i][j], v[i][j])
                    while s > res:
                        if v[i][j - s + 1] >= s and h[i - s + 1][j] >= s:
                            res = s
                            break
                        s -= 1
        return res**2