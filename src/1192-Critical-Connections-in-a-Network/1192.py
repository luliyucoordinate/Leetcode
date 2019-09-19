class Solution:
    def criticalConnections(self, n, connections):
        res, low, g = [], [None] * n, collections.defaultdict(list)
        for i, j in connections:
            g[i].append(j)
            g[j].append(i)

        def dfs(cur, v=0, p=None):
            dfn = low[v] = cur
            for i in g[v]:
                if i != p:
                    if low[i] == None: 
                        cur += 1
                        dfs(cur, i, v)
                        low[i] > dfn and res.append([v, i])
                    low[v] = min(low[v], low[i])
        dfs(0)
        return res