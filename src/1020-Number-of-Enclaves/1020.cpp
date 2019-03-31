static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numEnclaves(vector<vector<int>>& A) 
    {
        for (auto i = 0; i < A.size(); ++i) dfs(A, i, 0), dfs(A, i, A[i].size() - 1);
        for (auto j = 0; j < A[0].size(); ++j) dfs(A, 0, j), dfs(A, A.size() - 1, j);

        return accumulate(begin(A), end(A), 0, [](int s, vector<int> &r)
        { return s + accumulate(begin(r), end(r), 0); });
    }
private:
    void dfs(vector<vector<int>>& A, int i, int j) 
    {
        if (i < 0 or j < 0 or i == A.size() or j == A[i].size() or A[i][j] != 1) return;
        A[i][j] = 0;
        dfs(A, i + 1, j), dfs(A, i - 1, j), dfs(A, i, j + 1), dfs(A, i, j - 1);
    }
};