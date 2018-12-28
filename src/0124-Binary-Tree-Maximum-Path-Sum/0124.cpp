static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxPathSum(TreeNode* root) 
    {
        res = INT_MIN;
        maxPath(root);
        return res;
    }
    
private:
    int res;
    
    int maxPath(TreeNode* root)
    {
        if (!root)   return 0;
        int left = max(0, maxPath(root->left));
        int right = max(0, maxPath(root->right));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};