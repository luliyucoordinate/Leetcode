class Solution:
    def shortestPath(self, g: List[List[int]], k: int) -> int:
        r, c = len(g), len(g[0])
        if k >= r + c - 3:
            return r + c -2
        
        mem = {(0, 0):0}
        q, step = [(0, 0, 0)], 0
        
        while q:
            n = len(q)
            for _ in range(n):
                x, y, pre = q.pop(0)
                if pre > k: 
                    continue
                    
                if x == r - 1 and y == c - 1:
                    return step
                
                for i, j in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                    nx, ny = x + i, y + j
                    if 0 <= nx < r and 0 <= ny < c:
                        nPre = pre + 1 if g[nx][ny] == 1 else pre
                        if nPre < mem.get((nx, ny), float("inf")):
                            q.append((nx, ny, nPre))
                            mem[(nx, ny)] = nPre
            step += 1
        return -1