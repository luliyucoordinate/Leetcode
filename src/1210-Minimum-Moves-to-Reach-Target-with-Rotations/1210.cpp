class Solution 
{
public:
	int minimumMoves(vector<vector<int>> grid) 
    {
		int n = grid.size();
		enum { HORI = 0, VERT = 1 };
		int dp[100][100][2];
		memset(dp, 0x7F, sizeof dp);
		dp[0][0][HORI] = 0;
        
		for (int i = 0; i < n; ++i) 
        {
			for (int j = 0; j < n; ++j) 
            {
				if (j < n - 1 && grid[i][j] == 0 && grid[i][j + 1] == 0) 
                {
					if (j > 0) dp[i][j][HORI] = min(dp[i][j][HORI], dp[i][j - 1][HORI] + 1); // HORI RIGHT
					if (i > 0) dp[i][j][HORI] = min(dp[i][j][HORI], dp[i - 1][j][HORI] + 1); // HORI DOWN
				}
				if (i < n - 1 && grid[i][j] == 0 && grid[i + 1][j] == 0) {
					if (j > 0) dp[i][j][VERT] = min(dp[i][j][VERT], dp[i][j - 1][VERT] + 1); // VERT RIGHT
					if (i > 0) dp[i][j][VERT] = min(dp[i][j][VERT], dp[i - 1][j][VERT] + 1); // VERT DOWN
				}
				if (i < n - 1 && j < n - 1 && grid[i + 1][j] == 0 && grid[i][j + 1] == 0 && grid[i + 1][j + 1] == 0)
                {
					dp[i][j][HORI] = min(dp[i][j][HORI], dp[i][j][VERT] + 1); // COUNTER
					dp[i][j][VERT] = min(dp[i][j][VERT], dp[i][j][HORI] + 1); // CLOCK
                }
			}
		}
		int res = dp[n - 1][n - 2][HORI];
        return res == 0x7F7F7F7F ? -1 : res;
	}
};