class Solution:
    def maxEqualRowsAfterFlips(self, A: List[List[int]]) -> int:
        return max(collections.Counter(tuple(x ^ r[0] for x in r) for r in A).values())