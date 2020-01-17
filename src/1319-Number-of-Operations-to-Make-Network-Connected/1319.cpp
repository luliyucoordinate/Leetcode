class Solution 
{
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if (connections.size() < n - 1) return -1;
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        int res = n;
        for (auto& it : connections)
        {
            int x = find(it[0]), y = find(it[1]);
            if (x != y)
            {
                parent[x] = y, res--;
            }
        }
        return res - 1;
    }

private:
    vector<int> parent;
    
    int find(int x) 
    {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
};