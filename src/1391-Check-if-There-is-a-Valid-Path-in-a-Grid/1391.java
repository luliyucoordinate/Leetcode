class Solution {
    public boolean hasValidPath(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        int[] d = {0, 1, 0, -1, 0};
        int[][] p =  {{1, 0, 1, 0}, 
                      {0, 1, 0, 1}, 
                      {0, 1, 1, 0},
                      {1, 1, 0, 0},
                      {0, 0, 1, 1},
                      {1, 0, 0, 1}};

        Queue<int[]> q = new ArrayDeque();
        q.add(new int[]{0, 0});
        while (!q.isEmpty()) {
            int[] it = q.poll();
            int x = it[0], y = it[1];
            if (x == r - 1 && y == c - 1) return true;

            int k = grid[x][y];
            grid[x][y] = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[i + 1];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] > 0 && 
                    p[k - 1][i] == 1 && p[grid[nx][ny] - 1][i ^ 2] == 1) {
                    q.add(new int[]{nx, ny});
                }
            }
        }
        return false;
    }
}