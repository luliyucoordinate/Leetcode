class Solution:
    def makeConnected(self, n: int, con: List[List[int]]) -> int:
        if len(con) < n - 1:
            return -1
        
        parent, res = list(range(n)), n
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        for i, j in con:
            x, y = find(i), find(j)
            if x != y:
                parent[x] = y
                res -= 1
                
        return res - 1