static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isCompleteTree(TreeNode* root) 
    {
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        int i = 0;
        while (i < nodes.size() && nodes[i]) 
        {
            nodes.push_back(nodes[i]->left);
            nodes.push_back(nodes[i]->right);
            i++;
        }
        while (i < nodes.size() && !nodes[i]) i++;
        return i == nodes.size();
    }
};