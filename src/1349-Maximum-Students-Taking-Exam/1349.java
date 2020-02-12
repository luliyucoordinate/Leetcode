class Solution {
    public int maxStudents(char[][] seats) {
        r = seats.length;
        c = seats[0].length;
        
        match = new int[r * c][];
        int res = 0, cnt = 0;
        
        int[] vis = new int[r * c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j += 2) {
                if (seats[i][j] != '.') continue;
                Arrays.fill(vis, 0);
                int[] node = {i, j};
                if (find(node, vis, seats)) res++;
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++){
                if (seats[i][j] == '.') cnt++;
            }
        }
        return cnt - res;
    }
    
    private int[][] d = {{-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {0, 1}, {1, 1}};
    private int r, c;
    private int[][] match;
    
    private boolean find(int[] node, int[] vis, char[][] seats) {
        for (int[] it : d) {
            int nx = it[0] + node[0], ny = it[1] + node[1];
            if (nx >= 0 && nx < r && ny >= 0&& ny < c && vis[nx * c + ny] == 0 && seats[nx][ny] == '.') {
                vis[nx * c + ny] = 1;
                if (match[nx * c + ny] == null || find(match[nx * c + ny], vis, seats)) {
                    match[nx * c + ny] = node;
                    return true;
                }
            }
        }
        return false;
    }
}