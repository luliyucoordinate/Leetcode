class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int n = grid.length, m = grid[0].length;
        Integer[][] ret = new Integer[n][m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int t = j + k;
                ret[(i + t / m)%n][t % m] = grid[i][j];
            }
        }
        List<List<Integer>> res = new ArrayList();
        for (int i = 0; i < n; i++) {
            res.add(Arrays.asList(ret[i]));
        }
        return res;
    }
}