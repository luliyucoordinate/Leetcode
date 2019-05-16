static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    TreeNode* bstToGst(TreeNode* root) 
    {
        if (root->right) bstToGst(root->right);
        pre = root->val = pre + root->val;
        if (root->left) bstToGst(root->left);
        return root;
    }
private:
    int pre = 0;
};