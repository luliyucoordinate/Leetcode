static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) 
    {
        if (root->val < val)
        {
            TreeNode* res = new TreeNode(val);
            res->left = root;
            return res;
        }
        
        if (root->right != nullptr) root->right = insertIntoMaxTree(root->right, val);
        else
        {
            TreeNode* res = new TreeNode(val);
            root->right = res;
        }
        return root;
    }
};