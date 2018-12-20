class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        mem = [[0]*n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if i or j:
                    mem[i][j] = mem[i-1][j] + mem[i][j-1]
                else:
                    mem[i][j] = 1
                    
        return mem[-1][-1]

if __name__ == "__main__":
    m, n = 7, 3
    print(Solution().uniquePaths(m, n))