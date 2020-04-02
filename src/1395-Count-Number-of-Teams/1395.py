class Solution:
    def numTeams(self, rating: List[int]) -> int:
        if len(rating) < 3: return 0
    
        N = 100000
        def update(tr, x, v):
            i = x
            while i <= N:
                tr[i] += v
                i += i & -i

        def getPrefixSum(tr, x): 
            res, i = 0, x
            while i:
                res += tr[i]
                i -= i & -i
            return res

        def getSuffixSum(tr, i): 
            return getPrefixSum(tr, N) - getPrefixSum(tr, i - 1)

        leftTree, rightTree = [0] * (N + 1), [0] * (N + 1)
        for r in rating:
            update(rightTree, r, 1)

        res = 0
        for r in rating:
            update(rightTree, r, -1)
            res += getPrefixSum(leftTree, r - 1) * getSuffixSum(rightTree, r + 1) + \
                    getSuffixSum(leftTree, r + 1) * getPrefixSum(rightTree, r - 1) 
            update(leftTree, r, 1)
        return res