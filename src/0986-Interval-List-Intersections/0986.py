class Solution:
    def intervalIntersection(self, A: 'List[Interval]', B: 'List[Interval]') -> 'List[Interval]':
        res = list()
        i = j = 0
        while i < len(A) and j < len(B):
            l = max(A[i].start, B[j].start)
            r = max(A[i].end, B[j].end)
            if l <= r:
                res.append(Interval(l, r))
                
            if A[i].end < B[j].end:
                i += 1
            else:
                j += 1
                
        return res