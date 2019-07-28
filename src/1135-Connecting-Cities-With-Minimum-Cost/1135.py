class Solution:
    def minimumCost(self, N: int, connections: List[List[int]]) -> int:  
        if len(connections) < N - 1:
            return -1
        connections.sort(key=lambda a : a[2])
        parent = [i for i in range(N)]
        
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        res, e, k = 0, 0, 0
        while e < N - 1:
            u, v, w = connections[k]
            k += 1
            x, y = find(u-1), find(v-1)
            if x != y:
                e += 1
                res += w
                parent[x] = y
        return res