static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) 
    {
        vector<unordered_set<int>> graph(N);
        vector<int> res(N, 0);
        vector<int> count(N, 1);
        for (auto e : edges)
        {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        dfs1(graph, res, count);
        dfs2(graph, res, count, N);
        return res;
    }
private:
    void dfs1(const vector<unordered_set<int>>& graph, vector<int>& res, vector<int>& count, int node=0, int parent=-1)
    {
        for (int child : graph[node])
        {
            if (child != parent)
            {
                dfs1(graph, res, count, child, node);
                count[node] += count[child];
                res[node] += res[child] + count[child];
            }
        }
    }
    
    void dfs2(const vector<unordered_set<int>>& graph, vector<int>& res, vector<int>& count, int N, int node=0, int parent=-1)
    {
        for (int child : graph[node])
        {
            if (child != parent)
            {
                res[child] = res[node] - 2*count[child] + N;
                dfs2(graph, res, count, N, child, node);
            }
        }
    }
};