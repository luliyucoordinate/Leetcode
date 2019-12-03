class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        res = []
        for i, j in intervals:
            if toBeRemoved[0] >= j or toBeRemoved[1] <= i:
                res.append([i, j])
            else:
                if toBeRemoved[0] > i:
                    res.append([i, toBeRemoved[0]])
                if toBeRemoved[1] < j:
                    res.append([toBeRemoved[1], j])
        return res