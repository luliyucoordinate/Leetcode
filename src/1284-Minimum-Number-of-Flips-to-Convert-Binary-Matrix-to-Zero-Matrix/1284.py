from functools import reduce
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        r, c = len(mat), len(mat[0])
        start = reduce(operator.ior, [t << i * c + j for i, row in enumerate(mat) for j, t in enumerate(row)])
        
        q = [(start, 0)]
        seen = set([start])
        while q:
            cur, step = q.pop(0)
            if not cur:
                return step
            for i in range(r):
                for j in range(c):
                    ne = cur
                    for x, y in (i, j), (i, j + 1), (i, j - 1), (i + 1, j), (i - 1, j):
                        if x >= 0 and x < r and y >= 0 and y < c:
                            ne ^= 1 << x * c + y
                    if ne not in seen:
                        seen.add(ne)
                        q.append((ne, step + 1))
        return -1