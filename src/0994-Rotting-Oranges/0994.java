class Solution {
    public int orangesRotting(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        int[] d = new int[]{0, 1, 0, -1, 0};
        int step = 0, cnt = 0;
        Queue<int[]> q = new ArrayDeque();
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) cnt++;
                else if (grid[i][j] == 2) q.add(new int[]{i, j});
            }
        }
        
        while (!q.isEmpty()) {
            if (cnt == 0) return step;
            
            for (int k = q.size(); k > 0; k--) {
                int[] t = q.poll();
                int x = t[0], y = t[1];
                for (int i = 0; i < 4; i++) {
                    int nx = x + d[i], ny = y + d[i + 1];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 1) {
                        cnt--;
                        q.add(new int[]{nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            step++;
        }
        
        return cnt == 0 ? step : -1;
    }
}