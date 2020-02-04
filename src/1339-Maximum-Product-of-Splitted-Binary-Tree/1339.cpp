class Solution 
{
public:
    int maxProduct(TreeNode* root) 
    {
        total = dfs(root), dfs(root);
        return res % (int)(1e9 + 7);
    }
private:
    long long res = 0, total = 0;
    
    int dfs(TreeNode* root) 
    {
        if (!root) return 0;
        long long sub = root->val + dfs(root->left) + dfs(root->right);
        res = max(res, sub * (total - sub));
        return sub;
    }
};