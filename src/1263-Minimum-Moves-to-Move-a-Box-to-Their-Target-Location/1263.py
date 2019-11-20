class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        r, c = len(grid), len(grid[0])
        dire = [[0, 1], [0, -1], [-1, 0], [1, 0]]
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 'T':
                    T = (i, j)
                elif grid[i][j] == 'B':
                    B = (i, j)
                elif grid[i][j] == 'S':
                    S = (i, j)

        def check1(x, y):
            return x >= 0 and x < r and y >= 0 and y < c and grid[x][y] != '#'

        def canMoveTo(e, b, q, vis):
            while q:
                pre = q.pop(0)
                if pre == e:
                    return True

                for i, j in dire:
                    nx, ny = pre[0] + i, pre[1] + j
                    if check1(nx, ny) and \
                        (nx, ny) != b and (nx, ny) not in vis:
                        q.append((nx, ny))
                        vis.add((nx, ny))
            return False

        def move(e, q, vis):
            res = 0
            while q:
                for _ in range(len(q)):
                    b, p = q.pop(0)
                    if b == e:
                        return res
                    
                    for i, j in dire:
                        nx, ny = b[0] + i, b[1] + j
                        if check1(nx, ny) and \
                            check1(b[0] - i, b[1] - j) and\
                            ((nx, ny), b) not in vis and \
                            canMoveTo((b[0] - i, b[1] - j), b, [p], set([p])):
                            q.append(((nx, ny), b))
                            vis.add(((nx, ny), b))
                res += 1
            return -1

        return move(T, [(B, S)], set([(B, S)]))