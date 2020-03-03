class Solution {
    public int minCost(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Deque<int[]> q = new ArrayDeque();
        q.addLast(new int[]{0, 0, 0});
        int[][] d = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        boolean[][] vis = new boolean[m][n];
        int[][] dist = new int[m][n];
        for (int i = 0; i < m; i++) Arrays.fill(dist[i], 100000000);
        dist[0][0] = 0;
        
        while (!q.isEmpty()) {
            int[] t = q.pollFirst();
            int step = t[0], x = t[1], y = t[2];
            if (vis[x][y]) continue;
            vis[x][y] = true;
            
            for (int i = 1; i <= 4; i++) {
                int nx = x + d[i - 1][0];
                int ny = y + d[i - 1][1];
                int new_dist = step;
                if (grid[x][y] != i) new_dist++;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > new_dist) {
                    dist[nx][ny] = new_dist;
                    if (grid[x][y] != i) q.addLast(new int[]{dist[nx][ny], nx, ny});
                    else q.addFirst(new int[]{dist[nx][ny], nx, ny});
                }
            }
        }
        return dist[m - 1][n - 1];
    }
}