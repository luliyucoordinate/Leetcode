static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int distributeCoins(TreeNode* root) 
    {
        res = 0;
        dfs(root);
        return res;
    }
private:
    int res;
    
    int dfs(TreeNode* root)
    {
        if (root)
        {
            int l = dfs(root->left);
            int r = dfs(root->right);
            res += abs(l) + abs(r);
            return l + r + root->val - 1;
        }
        return 0;
    }
};