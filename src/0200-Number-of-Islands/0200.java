class Solution {
    public int numIslands(char[][] grid) {
        if (grid.length == 0) return 0;
        r = grid.length;
        c = grid[0].length;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    private int r, c;
    private int res = 0;
    private int[] d = {0, 1, 0, -1, 0};

    private void dfs(char[][] grid, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i];
            int ny = y + d[i + 1];
            if (0 <= nx && nx < r && 0 <= ny && ny < c && grid[nx][ny] == '1') {
                grid[nx][ny] = '0';
                dfs(grid, nx, ny);
            }
        }
    }
}