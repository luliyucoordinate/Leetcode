class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        res = [0, 0]
        for c in chips:
            res[c % 2] += 1
        return min(res)