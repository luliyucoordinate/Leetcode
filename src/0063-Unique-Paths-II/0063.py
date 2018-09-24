class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        mem = [[0]*n for _ in range(m)]
        mem[0][0] = 1
        
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 0:
                    if j:
                        mem[i][j] += mem[i][j - 1]
                    if i:
                        mem[i][j] += mem[i - 1][j]
                else:
                    mem[i][j] = 0
        
        return mem[m - 1][n - 1]  

if __name__ == "__main__":
    obstacleGrid = [['0', '1']]
    print(Solution().uniquePathsWithObstacles(obstacleGrid))