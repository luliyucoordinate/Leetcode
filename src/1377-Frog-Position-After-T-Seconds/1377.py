class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        g = [[] for _ in range(n + 1)]
        for i, j in edges:
            g[i].append(j)
            g[j].append(i)

        def dfs(fa, cur, t):
            if len(g[cur]) == 1 or t == 0:
                return cur == target
            res = sum(dfs(cur, i, t - 1) for i in g[cur] if i != fa)
            return res / (len(g[cur]) - (cur != 1))
        return dfs(-1, 1, t)