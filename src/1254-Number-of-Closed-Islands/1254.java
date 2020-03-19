class Solution {
    public int closedIsland(int[][] g) {
        r = g.length;
        c = g[0].length;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == 0) {
                    g[i][j] = res;
                    dfs(g, i, j);
                    res++;
                }
            }
        }
        Set color = new HashSet();
        color.add(0); color.add(1);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 || i == r - 1) color.add(g[i][j]);
                else if (j == 0 || j == c - 1) color.add(g[i][j]);
            }
        }
        return res - color.size();
    }
    
    private int[] d = {0, 1, 0, -1, 0};
    private int r, c;
    private int res = 2;

    private void dfs(int[][] g, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i];
            int ny = y + d[i + 1];
            if (0 <= nx && nx < r && 0 <= ny && ny < c && g[nx][ny] == 0) {
                g[nx][ny] = res;
                dfs(g, nx, ny);
            }
        }
    }
}