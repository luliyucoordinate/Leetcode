class Solution 
{
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) 
    {
        int r = A.size(), c = A[0].size();
        for (auto& row : A)
        {
            for (int i = 1; i < c; i++) row[i] += row[i - 1];
        }
        
        int res = 0, cur = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < c; i++)
        {
            for (int j = i; j < c; j++)
            {
                cnt.clear();
                cnt[0] = 1, cur = 0;
                for (int k = 0; k < r; k++)
                {
                    cur += A[k][j] - (i ?  A[k][i - 1] : 0);
                    res += cnt[cur - target];
                    cnt[cur]++;
                }
            }
        }
        return res;
    }
};