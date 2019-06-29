class Solution 
{
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) 
    {
        int n = A.size();
        int mem[n + 1] = {0};
        for (int i = 1; i <= n; ++i) 
        {
            int cur = 0;
            for (int j = 1; j <= K; ++j) 
            {
                if (i >= j) 
                {
                    cur = max(cur, A[i - j]);
                    mem[i] = max(mem[i], mem[i - j] + cur * j);
                }
            }
        }
        return mem[n];
    }
};