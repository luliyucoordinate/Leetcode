class Solution 
{
public:
    int countSquares(vector<vector<int>>& A) 
    {
        int res = 0;
        for (int i = 0; i < A.size(); i++) 
        {
            for (int j = 0; j < A[0].size(); j++)
            {
                if (i && j && A[i][j])
                    A[i][j] = min({A[i - 1][j], A[i][j - 1], A[i - 1][j - 1]}) + 1;
                res += A[i][j];
            }
        }
        return res;
    }
};