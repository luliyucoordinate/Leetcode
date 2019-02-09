static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        vector<int> parents(edges.size()+1, 0);
        for (int i = 0; i <= edges.size(); ++i) parents[i] = i;
        for (auto& edge : edges)
        {
            int i = find(parents, edge[0]), j = find(parents, edge[1]);
            if (i == j) return edge;
            else parents[i] = j;
        }
        return {};
    }
    
    int find(vector<int>& parents, int x)
    {
        if (x != parents[x]) parents[x] = find(parents, parents[x]);
        return parents[x];
    }
};