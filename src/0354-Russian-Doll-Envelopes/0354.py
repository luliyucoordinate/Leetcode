from bisect import bisect_left
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        if not envelopes:
            return 0
        
        res, n = 0, len(envelopes)
        envelopes.sort(key=lambda a:(a[0], -a[1]))
        mem = list()
        for e in envelopes:
            index = bisect_left(mem, e[1])
            if len(mem) == index:
                mem.append(e[1])
            else:
                mem[index] = e[1]
        return len(mem)