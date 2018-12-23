static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        TreeNode* cur = root;
        while (cur != nullptr)
        {
            if (cur->left != nullptr)
            {
                TreeNode* pre = cur->left;
                while (pre->right != nullptr)
                {
                    pre = pre->right;
                }
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};