class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        A = [[0]*n for _ in range(n)]
        i, j, di, dj = 0, 0, 0, 1
        for k in range(1,n**2+1):
            A[i][j] = k  
            if A[(i+di)%n][(j+dj)%n]:
                di, dj = dj, -di

            i += di
            j += dj

        return A     

if __name__ == "__main__":
    n = 4
    print(Solution().generateMatrix(n))