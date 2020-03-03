class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = collections.deque([(0, 0, 0)])
        d = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        vis = [[0] * n for _ in range(m)]
        dist = [[float("inf")] * n for _ in range(m)]
        dist[0][0] = 0
        
        while q:
            step, x, y = q.popleft()
            if vis[x][y]: continue
            vis[x][y] = 1

            for i in range(1, 5):
                nx, ny = d[i - 1][0] + x, d[i - 1][1] + y
                if 0 <= nx < m and 0 <= ny < n and dist[nx][ny] > step + (grid[x][y] != i):
                    dist[nx][ny] = step + (grid[x][y] != i)
                    if grid[x][y] != i: q.append((dist[nx][ny], nx, ny))
                    else: q.appendleft((dist[nx][ny], nx, ny))
        return dist[-1][-1]