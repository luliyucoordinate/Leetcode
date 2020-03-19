class Solution {
public:
    int closedIsland(vector<vector<int>>& g) {
        r = g.size(), c = g[0].size(), res = 2;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (g[i][j] == 0) {
                    g[i][j] = res;
                    dfs(g, i, j);
                    res++;
                }                
            }
        }
        unordered_set<int> color = {0, 1};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 || i == r - 1) color.emplace(g[i][j]);
                else if (j == 0 || j == c - 1) color.emplace(g[i][j]);
            }
        }
        return res - color.size();
    }
private:
    int d[5] = {0, 1, 0, -1, 0};
    int res, r, c;
    
    void dfs(vector<vector<int>>& g, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (0 <= nx && nx < r && 0 <= ny && ny < c && g[nx][ny] == 0) {
                g[nx][ny] = res;
                dfs(g, nx, ny);
            }
        }
    }
};