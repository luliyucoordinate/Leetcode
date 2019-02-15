static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int longestUnivaluePath(TreeNode* root) 
    {
        res = 0;
        longestUnivalue(root);
        return res;
    }
private:
    int res;
    
    int longestUnivalue(TreeNode* root)
    {
        if (root == nullptr) return 0;
        
        int l = longestUnivalue(root->left);
        int r = longestUnivalue(root->right);
        int pl = 0, pr = 0;
        if (root->left and root->left->val == root->val) pl = l + 1;
        if (root->right and root->right->val == root->val) pr = r + 1;
        res = max(res, pl + pr);
        return max(pl, pr);
    }
};