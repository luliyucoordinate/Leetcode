class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0

        mem = grid[0][:]
        r, c = len(grid), len(grid[0])
        for i in range(1, c):
            mem[i] += mem[i - 1]
        for j in range(1, r):
            mem[0] += grid[j][0]
            for i in range(1, c):
                mem[i] = min(mem[i - 1], mem[i]) + grid[j][i]

        return mem[-1]
        
        
if __name__ == '__main__':
    grid = [
            [1,3,1],
            [1,5,1],
            [4,2,1]
            ]
    print(Solution().minPathSum(grid))