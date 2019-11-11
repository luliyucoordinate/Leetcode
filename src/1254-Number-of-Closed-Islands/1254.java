class Solution {
    public int closedIsland(int[][] g) {
        int r = g.length, c = g[0].length, res = 2;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == 0) {
                    dfs(i, j, res++, g);
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
    
    private int[][] dire = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    private int check(int i, int j, int[][] g) {
        return (i < 0 || j < 0 || i >= g.length || j >= g[0].length) ? 0 : 1;
    }
    
    private void dfs(int i, int j, int color, int[][] g) {
        if (check(i, j, g) == 0 || g[i][j] != 0) return;
        g[i][j] = color;
        for (int[] d : dire) {
            dfs(d[0] + i, d[1] + j, color, g);
        }
    }
}