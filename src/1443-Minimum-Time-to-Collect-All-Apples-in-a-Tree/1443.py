class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        g = collections.defaultdict(list)
        for i, j in edges:
            g[i].append(j)
            g[j].append(i)
            
        vis = [False] * n
        vis[0] = True
        def dfs(x):
            res = 0
            for i in g[x]:
                if vis[i]: continue
                vis[i] = True
                
                cur = dfs(i)
                if cur: res += cur + 2
                elif hasApple[i]: res += 2

            return res
        return dfs(0)