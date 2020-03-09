class Solution 
{
public:
    int longestZigZag(TreeNode* root) 
    {
        dfs(root);
        return res;
    }
private:
    int res = 0;
    
    pair<int, int> dfs(TreeNode* root)
    {
        if (root == nullptr) return {-1, -1};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        res = max({res, left.second + 1, right.first + 1});
        return {left.second + 1, right.first + 1};
    }
};