class Solution {
    public boolean hasValidPath(int[][] grid) {
        r = grid.length; c = grid[0].length;
        return dfs(grid, 0, 0, 0) || dfs(grid, 0, 0, 1) || dfs(grid, 0, 0, 2) || dfs(grid, 0, 0, 3);
    }
    
    private int r, c;
    private int[][] d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private int[][] p = {{2, -1, 0, -1}, 
                        {-1, 3, -1, 1}, 
                        {-1, 2, 1, -1},
                        {1, 0, -1, -1},
                        {-1, -1, 3, 2},
                        {3, -1, -1, 0}};
    
    private boolean dfs(int[][] grid, int x, int y, int di) {
        if (p[grid[x][y] - 1][di] == -1) return false;
        if (x == r - 1 && y == c - 1) return true;
        
        int dx = d[p[grid[x][y] - 1][di]][0], dy = d[p[grid[x][y] - 1][di]][1];
        int nx = x + dx, ny = y + dy;
        if (0 <= nx && nx < r && 0 <= ny && ny < c) {
            if (dfs(grid, nx, ny, (p[grid[x][y] - 1][di] + 2) % 4)) return true;
        }
        return false;
    }
}