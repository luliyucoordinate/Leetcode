class Solution:
    def oddEvenJumps(self, A: List[int]) -> int:
        n = len(A)
        def st(data):
            s, res = [], [0]*n
            for i in data:
                while s and s[-1] < i:
                    res[s.pop()] = i
                s.append(i)
            return res
        
        d = sorted(range(n), key=lambda i: A[i])
        n1, n2 = st(d), st(sorted(d, key=lambda i: -A[i]))
        h, l = [0] * n, [0] * n
        h[-1] = l[-1] = 1
        for i in range(n - 2, -1, -1):
            h[i] = l[n1[i]]
            l[i] = h[n2[i]]
        return sum(h)