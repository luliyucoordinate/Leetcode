class Solution:
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
        for i, v in enumerate(wells):
            pipes.append([0, i+1, v])
        
        pipes.sort(key=lambda x:x[2])
        parents = [i for i in range(n + 1)]
        
        def find(x):
            if x != parents[x]:
                parents[x] = find(parents[x])
            return parents[x]
        
        res, e, k = 0, 0, 0
        while e < n:
            u, v, w = pipes[k]
            k += 1
            x, y = find(u), find(v)
            if x != y:
                e += 1
                res += w
                parents[x] = y
        return res