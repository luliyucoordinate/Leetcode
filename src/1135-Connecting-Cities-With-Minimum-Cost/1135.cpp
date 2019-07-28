class Solution 
{
public:
    int minimumCost(int N, vector<vector<int>>& connections) 
    {
        if (connections.size() < N - 1) return -1;
        for (int i = 0; i < N; ++i) parent.push_back(i);
        sort(connections.begin(), connections.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int e = 0, res = 0, k = 0;
        while (e < N - 1)
        {
            auto pre = connections[k++];
            int x = find(pre[0] - 1), y = find(pre[1] - 1);
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