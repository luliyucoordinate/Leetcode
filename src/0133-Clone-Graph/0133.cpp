static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if (!node) return nullptr;
        if (!visited.count(node)) 
        {
            visited[node] = new UndirectedGraphNode(node->label);
            for (UndirectedGraphNode* neigh : node->neighbors)
                visited[node]->neighbors.push_back(cloneGraph(neigh));
        }
        return visited[node];
    } 
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
};