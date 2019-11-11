class Solution:
    def closedIsland(self, g: List[List[int]]) -> int:
        dire = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        r, c = len(g), len(g[0])
              
        def check(x, y):
            if x < 0 or x >= r or y < 0 or y >= c:
                return 0
            return 1
        
        def dfs(x, y, color):
            if not check(x, y) or g[x][y] != 0:
                return 
            g[x][y] = color
            for i, j in dire:
                dfs(x + i, y + j, color)

        res = 2
        for i in range(r):
            for j in range(c):
                if g[i][j] == 0:
                    dfs(i, j, res)
                    res += 1
        
        color = set([0, 1])
        for i in range(r):
            for j in range(c):
                if i == 0 or i == r - 1:
                    color.add(g[i][j])
                elif j == 0 or j == c - 1:
                    color.add(g[i][j])
        return res - len(color)