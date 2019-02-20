class Solution 
{
public:
    int findClosestLeaf(TreeNode* root, int k) 
    {
        _start = nullptr;
        buildGraph(root, nullptr, k);
        queue<TreeNode*> q;
        q.push(_start);
        unordered_set<TreeNode*> visited;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* cur = q.front(); q.pop()
                visited.insert(cur);
                if (!cur->left and !cur->right) return cur->val;
                for (TreeNode* node : _graph[cur])
                    if (!visited.count(node)) q.push(node);
            }
        }
    }

private:
    unordered_map<TreeNode*, vector<TreeNode*>> _graph;
    TreeNode* _start;

    void buildGraph(TreeNode* node, TreeNode* parent, int k) 
    {
        if (!node) return;
        if (node->val == k) _start = node;
        if (parent)
        {
            _graph[node].push_back(parent);
            _graph[parent].push_back(node);
        }
        buildGraph(node->left, node, k);
        buildGraph(node->right, node, k);
    }
};