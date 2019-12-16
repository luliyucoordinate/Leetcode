class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& A)
    {
        int r = A.size(), c = A[0].size();
        for (int i = r - 1; i > 0; i--)
        {
            int m1[2] = {INT_MAX, 0}, m2[2] = {INT_MAX, 0};
            for (int k = 0; k < c; k++)
            {
                if (A[i][k] < m1[0]) 
                {
                    memcpy(m2, m1, sizeof m1);
                    m1[0] = A[i][k], m1[1] = k;
                } else if (A[i][k] < m2[0]) m2[0] = A[i][k], m2[1] = k;
            }
            
            for (int j = 0; j < c; j++) 
            {
                A[i-1][j] += (j != m1[1] ? m1[0] : m2[0]);
            }
        }
        return *min_element(A[0].begin(), A[0].end());
    }
};