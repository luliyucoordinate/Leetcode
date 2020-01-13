class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        r, c = len(mat), len(mat[0])
        pre = [[0] * (c + 1) for _ in range(r + 1)]
        for i in range(r):
            for j in range(c):
                pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + mat[i][j]
                
        res = [[0] * c for _ in range(r)]        
        for i in range(r):
            for j in range(c):
                r1, c1, r2, c2 = max(0, i - K), max(0, j - K), min(r, i + K + 1), min(c, j + K + 1)
                res[i][j] = pre[r2][c2] - pre[r1][c2] - pre[r2][c1] + pre[r1][c1]
        return res