class Solution 
{
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) 
    {
        for (int i = 0; i < wells.size(); ++i) pipes.push_back({0, i+1, wells[i]});
        for (int i = 0; i <= n; ++i) parent.push_back(i);
        sort(pipes.begin(), pipes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        int e = 0, res = 0, k = 0;
        while (e < n)
        {
            auto pre = pipes[k++];
            int x = find(pre[0]), y = find(pre[1]);
            if (x != y)
            {
                parent[x] = y;
                e++;
                res += pre[2];
            }
        }
        return res;
    }
    
    vector<int> parent;
    int find(int x)
    {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
};