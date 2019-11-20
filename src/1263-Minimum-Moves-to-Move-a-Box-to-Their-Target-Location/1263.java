class Solution {
    public int minPushBox(char[][] grid) {
        r = grid.length; c = grid[0].length;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 'T') T = new int[]{i, j};
                else if (grid[i][j] == 'S') S = new int[]{i, j};
                else if (grid[i][j] == 'B') B = new int[]{i, j};
            }
        }

        int res = 0;
        Queue<int[]> q = new LinkedList();
        q.offer(new int[]{B[0], B[1], S[0], S[1]});
        boolean[][][][] vis = new boolean[21][21][21][21];
        vis[B[0]][B[1]][S[0]][S[1]] = true;
        while (!q.isEmpty()) {
            int n = q.size();
            while (n-- > 0) {
                int[] p = q.poll(); 
                if (p[0] == T[0] && p[1] == T[1]) return res;

                for (int[] it : dire)
                {
                    int nx = it[0] + p[0], ny = it[1] + p[1];
                    int[] e = new int[]{p[0] - it[0], p[1] - it[1]};
                    int[] b = new int[]{p[0], p[1]};
                    int[] s = new int[]{p[2], p[3]};
                    if (check(nx, ny, grid) && check(e[0], e[1], grid) &&
                       !vis[nx][ny][p[0]][p[1]] && canMoveTo(e, b, s, grid))
                    {
                        q.offer(new int[]{nx, ny, p[0], p[1]});
                        vis[nx][ny][p[0]][p[1]] = true;
                    }
                }
            }
            res++;
        }
        return -1;
    }

    private int r, c;
    private int[] B, S, T;
    private int[][] dire = new int[][]{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    private boolean check(int x, int y, char[][] grid) {
        return x >= 0 && x < r && y >= 0 && y < c && grid[x][y] != '#';
    }
    
    private boolean canMoveTo(int[] e, int[] b, int[] s, char[][] grid) {
        Queue<int[]> q = new LinkedList();
        q.offer(s);
        boolean[][] vis = new boolean[21][21];
        vis[s[0]][s[1]] = true;
        while (!q.isEmpty()) {
            int[] pre = q.poll();
            if (pre[0] == e[0] && pre[1] == e[1]) return true;

            for (int[] it : dire) {
                int nx = pre[0] + it[0], ny = pre[1] + it[1];
                if (check(nx, ny, grid) && 
                    (nx != b[0] || ny != b[1]) && !vis[nx][ny])
                {
                    q.offer(new int[]{nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
        return false;
    }
}