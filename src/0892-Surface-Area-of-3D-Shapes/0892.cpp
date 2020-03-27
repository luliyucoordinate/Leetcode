class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0, r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) res += grid[i][j] * 4 + 2;
                if (i) res -= min(grid[i - 1][j], grid[i][j]) * 2;
                if (j) res -= min(grid[i][j - 1], grid[i][j]) * 2;
            }
        }
        return res;
    }
};