class Solution:
    def closedIsland(self, g: List[List[int]]) -> int:
        d = [0, 1, 0, -1, 0]
        r, c, res = len(g), len(g[0]), 2
              
        def dfs(x, y):
            for i in range(4):
                nx, ny = x + d[i], y + d[i + 1]
                if 0 <= nx < r and 0 <= ny < c and g[nx][ny] == 0:
                    g[nx][ny] = res
                    dfs(nx, ny)

        for i in range(r):
            for j in range(c):
                if g[i][j] == 0:
                    g[i][j] = res
                    dfs(i, j)
                    res += 1
        
        color = set([0, 1])
        for i in range(r):
            for j in range(c):
                if i == 0 or i == r - 1:
                    color.add(g[i][j])
                elif j == 0 or j == c - 1:
                    color.add(g[i][j])
        return res - len(color)