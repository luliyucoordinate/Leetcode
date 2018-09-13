class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
            
        result = 0
        m, n = len(grid), len(grid[0])
        for row in range(m):
            for col in range(n):
                if grid[row][col] == '1':
                    result += 1
                    self._numIslands(grid, row, col)
        return result

    def _numIslands(self, grid, r, c):
        grid[r][c] = '0'
        if 0 < r and grid[r - 1][c] == '1':
            self._numIslands(grid, r - 1,c)

        if 0 < c and grid[r][c - 1] == '1':
            self._numIslands(grid, r, c - 1)

        if c < len(grid[0]) -1 and grid[r][c + 1] =='1':
            self._numIslands(grid, r, c + 1)

        if r < len(grid) - 1 and grid[r + 1][c] == '1':
            self._numIslands(grid, r + 1, c)


if __name__ == '__main__':
    grid =[
            ['1','1','1','1','0'],
            ['1','1','0','1','0'],
            ['1','1','0','0','0'],
            ['0','0','0','0','0']
            ]
    print(Solution().numIslands(grid))
