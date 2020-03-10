class Solution 
{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        son.resize(n);
        for (int i = 0; i < manager.size(); i++)
        {
            if (manager[i] != -1) son[manager[i]].emplace_back(i);
        }
        
        return dfs(headID, informTime);
    }
    
private:
    vector<vector<int>> son;
    
    int dfs(int x, vector<int>& informTime)
    {
        int res = 0;
        for(int n : son[x])
            res = max(res, dfs(n, informTime));		
        return res + informTime[x];				
    }
};