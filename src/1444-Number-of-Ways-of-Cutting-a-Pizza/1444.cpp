class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        r = pizza.size(), c = pizza[0].size();

        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                g[i][j] = g[i + 1][j] + g[i][j + 1] - g[i + 1][j + 1] + int(pizza[i][j] == 'A');
            }
        }

        return dfs(0, 0, k - 1);
    }
private:
    int mod = 1000000007, r, c;
    int g[51][51] = {};
    int dp[51][51][11] = {};
    
    
    int dfs(int i, int j, int k) {
        if (dp[i][j][k] != 0) return dp[i][j][k];
        if (g[i][j] == 0) return 0;
        if (k == 0) return 1;
        
        int res = 0;
        for (int x = i + 1; x < r; x++) {
            if (g[i][j] - g[x][j] > 0) res = (res + dfs(x, j, k - 1)) % mod;
        }
        for (int y = j + 1; y < c; y++) {
            if (g[i][j] - g[i][y] > 0) res = (res + dfs(i, y, k - 1)) % mod;
        }
        dp[i][j][k] = res;
        return res;
    }
};