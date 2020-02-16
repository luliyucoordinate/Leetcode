class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        r, c, res = len(grid), len(grid[0]), 0
        m, n = r - 1, 0
        
        while m >= 0 and n < c:
            if grid[m][n] < 0:
                res += c - n
                m -= 1
            else:
                n += 1
        return res