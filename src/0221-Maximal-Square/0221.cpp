class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if (matrix.empty()) return 0;
        int res = 0, r = matrix.size(), c = matrix[0].size();
        int mem[r][c] = {};
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (!i or !j or matrix[i][j] == '0') mem[i][j] = matrix[i][j] - '0';
                else mem[i][j] = min({mem[i-1][j], mem[i][j-1], mem[i-1][j-1]}) + 1;
                res = max(res, mem[i][j]);
            }
        }
        return res * res;
    }
};