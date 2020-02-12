class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        r, c = len(seats), len(seats[0])
        match = [[-1] * c for _ in range(r)]
        
        def find(node, vis):
            x, y = node
            for i, j in [[-1, -1], [0, -1], [1, -1], [-1, 1], [0, 1], [1, 1]]:
                nx, ny = i + x, j + y
                if 0 <= nx < r and 0 <= ny < c and not vis[nx][ny] and seats[nx][ny] == '.':
                    vis[nx][ny] = True
                    if match[nx][ny] == -1 or find(match[nx][ny], vis):
                        match[nx][ny] = node
                        return True
            return False
        
        res, cnt = 0, 0
        for i in range(r):
            for j in range(0, c, 2):
                if seats[i][j] != '.': continue
                vis = [[False] * c for _ in range(r)]
                if find((i, j), vis): res += 1
        
        for i in range(r):
            for j in range(c):
                if seats[i][j] == '.': cnt += 1
        return cnt - res