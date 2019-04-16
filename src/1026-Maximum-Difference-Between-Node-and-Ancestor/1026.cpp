static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxAncestorDiff(TreeNode* root, int mx=INT_MIN, int mn=INT_MAX) 
    {
        return root == nullptr ? mx - mn : max(maxAncestorDiff(root->left, max(mx, root->val), min(mn, root->val)),
                                              maxAncestorDiff(root->right, max(mx,root->val), min(mn, root->val)));
    }
};