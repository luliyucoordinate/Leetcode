class Solution 
{
public:
    int longestArithSeqLength(vector<int>& A) 
    {
        const int cM = 10000;
        int n = A.size(), res = 0;
        vector<int> idx(cM + 1, -1);
        vector<vector<int>> f(n, vector<int>(n, 0));
        
        for (int i = 0; i < n - 1; ++i) 
        {
            for (int j = i + 1; j < n; ++j) 
            {
                int pre = A[i] * 2 - A[j];
                if (pre >= 0 && pre <= cM && idx[pre] != -1) f[i][j] = f[idx[pre]][i] + 1;
                else f[i][j] = 2;
                res = max(res, f[i][j]);
            }
            idx[A[i]] = i;
        }
        return res;
    }
};