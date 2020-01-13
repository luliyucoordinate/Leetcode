class Solution 
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) 
    {
        int r = mat.size(), c = mat[0].size();
        vector<vector<int>> pre = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));
        
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + mat[i][j];
            }
        }
        
        vector<vector<int>> res = vector<vector<int>>(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) 
        {
            for (int j = 0; j < c; j++) 
            {
                int r1 = max(0, i - K), c1 = max(0, j - K), r2 = min(r, i + K + 1), c2 = min(c, j + K + 1);
                res[i][j] = pre[r2][c2] - pre[r1][c2] - pre[r2][c1] + pre[r1][c1];
            }
        }
        return res;
    }
};