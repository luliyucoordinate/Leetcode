class Solution 
{
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        return dfs(root).second;
    }
    
    pair<int, TreeNode*> dfs(TreeNode* root) 
    {
        if (root == nullptr) return {0, nullptr};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        if (l.first < r.first) return {r.first + 1, r.second};
        else if (l.first > r.first) return {l.first + 1, l.second};
        else return {l.first + 1, root};
    }
};