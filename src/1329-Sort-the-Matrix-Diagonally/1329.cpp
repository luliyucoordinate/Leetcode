class Solution 
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int r = mat.size(), c = mat[0].size();
        int t[min(r, c)] = {0};
        for (int i = 0; i < r; i++)
        {
            int k = min(r - i, c);
            for (int j = 0; j < k; j++) t[j] = mat[i + j][j];
            sort(t, t + k);
            for (int j = 0; j < k; j++) mat[i + j][j] = t[j];
        }
        
        for (int i = 1; i < c; i++)
        {
            int k = min(c - i, r);
            for (int j = 0; j < k; j++) t[j] = mat[j][i + j];
            sort(t, t + k);
            for (int j = 0; j < k; j++) mat[j][i + j] = t[j];
        }
        return mat;
    }
};