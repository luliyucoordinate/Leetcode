class Solution 
{
public:
    int smallestCommonElement(vector<vector<int>>& mat) 
    {
        int r = mat.size(), c = mat[0].size();
        for (int i = 0; i < c; ++i) 
        {
            for (int j = 1; j < r; ++j)
            {
                int k = lower_bound(mat[j].begin(), mat[j].end(), mat[0][i]) - mat[j].begin();
                if (mat[j][k] == mat[0][i]) continue;
                else goto b;
            }
            return mat[0][i];
            b:; 
        }
        return -1;
    }
};