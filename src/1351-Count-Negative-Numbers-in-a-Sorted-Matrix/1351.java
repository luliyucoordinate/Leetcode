class Solution {
    public int countNegatives(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        int res = 0, m = r - 1, n = 0;
        
        while (m >= 0 && n < c) {
            if (grid[m][n] < 0) {
                res += c - n;
                m--;
            } else n++;
        }
        return res;
    }
}