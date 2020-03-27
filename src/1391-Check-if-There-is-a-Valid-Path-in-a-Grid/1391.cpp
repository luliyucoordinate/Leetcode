typedef pair<int, int> PII;
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int d[5] = {0, 1, 0, -1, 0};
        int p[6][4] =  {{1, 0, 1, 0}, 
                        {0, 1, 0, 1}, 
                        {0, 1, 1, 0},
                        {1, 1, 0, 0},
                        {0, 0, 1, 1},
                        {1, 0, 0, 1}};

        queue<PII> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto pre = q.front(); q.pop();
            int x = pre.first, y = pre.second;
            if (x == r - 1 && y == c - 1) return true;

            int k = grid[x][y];
            grid[x][y] = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[i + 1];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] && 
                    p[k - 1][i] && p[grid[nx][ny] - 1][i ^ 2]) {
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }
};