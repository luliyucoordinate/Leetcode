class Solution 
{
public:
    int maxJumps(vector<int>& arr, int d) 
    {
        n = arr.size(), td = d;
        
        lb = vector<int>(n, -1);
        rb = vector<int>(n, -1);
        findBiggerRight(arr, rb);
        findBiggerLeft(arr, lb);

        dp = vector<int>(n);
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, dfs(i));
        return res;
    }
private:
    vector<int> dp, lb, rb;
    int n, td;
    
    void findBiggerRight(vector<int>& arr, vector<int>& res)
    {
        deque<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && s.front() < i - td) s.pop_front();
            while (!s.empty() && arr[s.back()] < arr[i]) 
            {
                res[s.back()] = i;
                s.pop_back();
            }
            s.emplace_back(i);
        }
    }
    
    void findBiggerLeft(vector<int>& arr, vector<int>& res)
    {
        deque<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && s.front() < i - td) s.pop_front();
            while (!s.empty() && arr[s.back()] <= arr[i]) s.pop_back();
            if (!s.empty()) res[i] = s.back();
            s.emplace_back(i);
        }
    }
    
    int dfs(int u)
    {
        if (dp[u]) return dp[u];
        dp[u] = 1;
        if (lb[u] >= 0) dp[u] = max(dp[u], dfs(lb[u]) + 1);
        if (rb[u] >= 0) dp[u] = max(dp[u], dfs(rb[u]) + 1);
        return dp[u];
    }
};