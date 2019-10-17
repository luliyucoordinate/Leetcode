class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
            
        res, r, c = 0, len(matrix), len(matrix[0])
        mem = [[0]*c for _ in range(r)]

        for i in range(r):
            for j in range(c):
                if not i or not j or matrix[i][j] == '0':
                    mem[i][j] = int(matrix[i][j])
                else:
                    mem[i][j] = min(mem[i-1][j], mem[i-1][j-1], mem[i][j-1]) + 1
                res = max(res, mem[i][j])
        return res**2