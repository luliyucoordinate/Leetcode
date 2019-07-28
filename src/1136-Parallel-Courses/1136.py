class Solution:
    def minimumSemesters(self, N: int, relations: List[List[int]]) -> int:
        g, d = collections.defaultdict(list), [0] * N
        for i, j in relations:
            g[i - 1].append(j - 1)
            d[j - 1] += 1
        
        q, resLen, res = list(), 0, 0
        for i in range(N):
            if d[i] == 0:
                q.append(i)
                resLen += 1
        
        while len(q):
            n = len(q)
            for _ in range(n):
                pre = q.pop(0)
                for i in g[pre]:
                    d[i] -= 1
                    if d[i] == 0:
                        q.append(i)
                        resLen += 1
            res += 1
        
        return res if resLen == N else -1