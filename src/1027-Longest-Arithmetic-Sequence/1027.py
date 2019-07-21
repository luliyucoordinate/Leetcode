class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        n, res, cM = len(A), 0, 10000
        idx = [-1]*(cM + 1)
        f = [[0]*n for _ in range(n)]
        
        for i in range(n - 1):
            for j in range(i + 1, n):
                pre = A[i] * 2 - A[j]
                if pre >= 0 and pre <= cM and idx[pre] != -1:
                    f[i][j] = f[idx[pre]][i] + 1
                else:
                    f[i][j] = 2
                res = max(res, f[i][j])
            idx[A[i]] = i
        return res