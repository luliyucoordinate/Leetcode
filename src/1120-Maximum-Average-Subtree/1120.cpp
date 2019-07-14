class Solution 
{
public:
    double maximumAverageSubtree(TreeNode* root) 
    {
        dfs(root);
        return res;
    }
    
    double res = 0.0;
    pair<int, int> dfs(TreeNode* root)
    {
        if (root == nullptr) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int values = l.first + r.first + root->val;
        int nodes = l.second + r.second + 1;
        res = max(res, values*1.0/nodes);
        return {values, nodes};
    }
};