class Solution:
    def numSubmatrixSumTarget(self, A: List[List[int]], target: int) -> int:
        r, c = len(A), len(A[0])
        for row in A:
            for i in range(1, c):
                row[i] += row[i - 1]
                
        res = 0
        for i in range(c):
            for j in range(i, c):
                cnt = collections.defaultdict(int)
                cur, cnt[0] = 0, 1
                for k in range(r):
                    cur += A[k][j] - (A[k][i - 1] if i > 0 else 0)
                    res += cnt[cur - target]
                    cnt[cur] += 1
        return res