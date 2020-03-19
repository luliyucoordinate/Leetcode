class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        r = grid.size(), c = grid[0].size();
        int res = 0;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
private:
    int d[5] = {0, 1, 0, -1, 0};
    int r, c;

    int dfs(vector<vector<int>>& grid, int x, int y) {
        int res = 1;
        for (int i = 0; i < 4; i++) {
            int nx = d[i] + x, ny = d[i + 1] + y;
            if (0 <= nx && nx < r && 0 <= ny && ny < c && grid[nx][ny] == 1) {
                grid[nx][ny] = 0;
                res += dfs(grid, nx, ny);
            }
        }
        return res;
    }
};