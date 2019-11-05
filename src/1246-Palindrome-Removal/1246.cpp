class Solution 
{
public:
    int minimumMoves(vector<int>& arr) 
    {
        int n = arr.size();
        int mem[n + 1][n + 1] = {};
        for (int l = 1; l <= n; l++) 
        {
            int i = 0, j = l - 1;
            while (j < n)
            {
                if (l == 1) mem[i][j] = 1;
                else 
                {
                    mem[i][j] = mem[i + 1][j] + 1;
                    for (int k = i + 1; k <= j; k++)
                    {
                        if (arr[k] == arr[i]) 
                            mem[i][j] = min(mem[i][j], mem[i + 1][k - 1] + mem[k + 1][j] + (i + 1 == k));
                    }
                }
                ++i, ++j;
            }
        }
        return mem[0][n - 1];
    }
};