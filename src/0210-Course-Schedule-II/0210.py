class Solution:
    def findOrder(self, n: int, prerequisites: List[List[int]]) -> List[int]:
        g = collections.defaultdict(list)
        d, vis, q, res = [0] * n, [0] * n, [], []
        for i, j in prerequisites:
            g[j].append(i)
            d[i] += 1
            
        for i in range(n):
            if d[i] == 0:
                q.append(i)
                vis[i] = 1
        
        while q:
            cur = q.pop(0)
            res.append(cur)
            n -= 1
            for i in g[cur]:
                d[i] -= 1
                if not vis[i] and d[i] == 0:
                    vis[i] = 1
                    q.append(i)
        return res if n == 0 else []