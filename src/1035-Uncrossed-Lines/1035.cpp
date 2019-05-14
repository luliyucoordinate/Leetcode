static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) 
    {
        int m = A.size(), n = B.size();
        vector<vector<int>> mem(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i) 
        {
            for (int j = 1; j <= n; ++j) 
            {
                if (A[i-1] == B[j-1]) mem[i][j] = mem[i-1][j-1] + 1;
                else mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
            }
        }
        return mem[m][n];
    }
};