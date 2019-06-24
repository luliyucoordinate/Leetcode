class Solution:
    def minMeetingRooms(self, intervals):
        if not intervals:
            return 0
        tmp = sorted(x for i, j in intervals for x in [[i, 1], [j, -1]])
        res, n = 0, 0
        for _, v in tmp:
            n += v
            res = max(res, n)
        return res