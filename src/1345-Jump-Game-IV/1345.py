class Solution:
    def minJumps(self, arr: List[int]) -> int:
        g, n = collections.defaultdict(list), len(arr)
        for i, v in enumerate(arr):
            g[v].append(i)
        
        vis, values = [0] * n, set()
        q, vis[0], step = [0], 1, 0
        
        while q:
            k = len(q)
            for _ in range(k):
                pre = q.pop(0)
                if pre == n - 1: return step
                
                for i in [pre - 1, pre + 1]:
                    if 0 <= i < n and not vis[i]:
                        vis[i] = 1
                        q.append(i)
                
                if arr[pre] in values: continue
                values.add(arr[pre])
                for i in g[arr[pre]]:
                    if not vis[i]:
                        vis[i] = 1
                        q.append(i)
            step += 1
        return step