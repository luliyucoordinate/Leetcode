class Solution {
    public int shortestPath(int[][] g, int k) {
        int r = g.length, c = g[0].length, step = 0;
        if (k >= r + c - 3) return r + c - 2;
        
        int[][] mem = new int[r][c];
        for (int i = 0; i < r; i++) {
            Arrays.fill(mem[i], 10000);
        }
        
        Queue<int[]> q = new LinkedList();
        q.offer(new int[]{0, 0, 0});
        mem[0][0] = 0;
        
        int[] d = {0, 1, 0, -1, 0};
        
        while (!q.isEmpty()) {
            for (int n = q.size(); n > 0; n--) {
                int[] pre = q.poll();
                if (pre[2] > k) continue;
                if (pre[0] == r - 1 && pre[1] == c - 1) return step;
                
                for (int i = 0; i < 4; i++) {
                    int nx = pre[0] + d[i], ny = pre[1] + d[i+1];
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                        int nPre = g[nx][ny] == 1 ? pre[2] + 1 : pre[2];
                        if (nPre < mem[nx][ny]) {
                            q.offer(new int[]{nx, ny, nPre});
                            mem[nx][ny] = nPre;
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
}