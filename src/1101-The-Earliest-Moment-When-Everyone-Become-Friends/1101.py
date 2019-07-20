class Solution:
    def earliestAcq(self, logs: List[List[int]], N: int) -> int:
        logs.sort(key=lambda a:a[0])
        s = dict()
        def find(x):
            s.setdefault(x, x)
            if s[x] != x:
                s[x] = find(s[x])
            return s[x]
            
        cnt = 0
        for t, x, y in logs:
            rx, ry = find(x), find(y)
            if rx != ry:
                s[rx] = ry
                cnt += 1
            if cnt == N - 1:
                return t
        return -1