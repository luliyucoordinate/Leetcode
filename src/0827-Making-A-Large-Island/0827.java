class Solution {
    public int largestIsland(int[][] g) {
        List<Integer> data = new ArrayList();
        data.add(0); data.add(0);
        int r = g.length, c = g[0].length;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == 1) data.add(dfs(i, j, data.size(), g));
            }
        }
        int res = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] != 0) continue;
                Set<Integer> s = new HashSet();
                int tmp = 0;
                for (int[] d : dire) {
                    int color = check(i + d[0], j + d[1], g);
                    if (!s.add(color)) continue;
                    tmp += data.get(color);
                }
                res = Math.max(res, tmp + 1);
            }
        }
        return res == 0 ? r * c : res;
    }
    private int[][] dire = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    private int check(int i, int j, int[][] g) {
        return (i < 0 || j < 0 || i >= g.length || j >= g[0].length) ? 0 : g[i][j];
    }
    
    private int dfs(int i, int j, int color, int[][] g) {
        if (check(i, j, g) != 1) return 0;
        g[i][j] = color;
        int res = 1;
        for (int[] d : dire) {
            res += dfs(d[0] + i, d[1] + j, color, g);
        }
        return res;
    }
}