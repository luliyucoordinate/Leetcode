class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        r, c = len(mat), len(mat[0])

        for i in range(r):
            t, k = [], min(r - i, c)
            for j in range(k):
                t.append(mat[i + j][j])
                
            t.sort()
            for j in range(k):
                mat[i + j][j] = t[j]
        
        for i in range(1, c):
            t, k = [], min(c - i, r)
            for j in range(k):
                t.append(mat[j][i + j])
            
            t.sort()
            for j in range(k):
                mat[j][i + j] = t[j]
        return mat