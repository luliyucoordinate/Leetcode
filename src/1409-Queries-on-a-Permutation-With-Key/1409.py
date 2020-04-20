class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        n = len(queries)
        tree, pos = [0] * (m + n + 1), [0] * (m + 1)
        res = []
        
        def update(i, v):
            while i < len(tree):
                tree[i] += v
                i += i & -i
    
        def prefixSum(i):
            res = 0 
            while i:
                res += tree[i]
                i -= i & -i
            return res

        for i in range(1, m + 1):
            update(i + n, 1)
            pos[i] = n + i

        for i in queries:
            res.append(prefixSum(pos[i] - 1))
            update(pos[i], -1)
            update(n, 1)
            pos[i] = n
            n -= 1
        return res