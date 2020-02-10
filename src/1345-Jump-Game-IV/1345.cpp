class Solution 
{
public:
    int minJumps(vector<int>& arr) 
    {
        unordered_map<int, vector<int>> g;
        unordered_set<int> values;
        int n = arr.size(), step = 0;
        for (int i = 0; i < n; i++) g[arr[i]].push_back(i);
        
        int vis[n] = {};
        vis[0] = 1;
        
        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int k = q.size();
            while (k--)
            {
                int pre = q.front(); q.pop();
                if (pre == n - 1) return step;
                
                if (pre - 1 >= 0 && !vis[pre - 1]) 
                {
                    vis[pre - 1] = 1; q.push(pre - 1);
                }
                
                if (pre + 1 < n && !vis[pre + 1])
                {
                    vis[pre + 1] = 1; q.push(pre + 1);
                }
                
                if (values.count(arr[pre])) continue;
                values.insert(arr[pre]);
                for (int i : g[arr[pre]])
                {
                    if (!vis[i])
                    {
                        vis[i] = 1; q.push(i);
                    }
                }
            }
            step++;
        }
        return step;
    }
};