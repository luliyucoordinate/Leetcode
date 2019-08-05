class Solution 
{
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) 
    {
        dfs(root, x);
        return max({l, r, n - l - r - 1}) > n / 2;
    }
    int l, r;
    int dfs(TreeNode* node, int x)
    {
        if (node == nullptr) return 0;
        auto m = dfs(node->left, x);
        auto n = dfs(node->right, x);
        if (node->val == x) l = m, r = n;
        return m + n + 1;
    }
};