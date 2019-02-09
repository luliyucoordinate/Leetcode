static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        vector<int> visited(M.size(), 0);
        int res = 0;
        for (int i = 0; i < M.size(); ++i)
        {
            if (!visited[i])
            {
                dfs(M, visited, i);
                ++res;                
            }
        }
            
        return res;
    }
    
    void dfs(vector<vector<int>>& M, vector<int>& visited, int i)
    {
        for (int j = 0; j < M.size(); ++j)
        {
            if (!visited[j] and M[i][j])
            {
                visited[j] = 1;
                dfs(M, visited, j);
            }
        }
    }
};