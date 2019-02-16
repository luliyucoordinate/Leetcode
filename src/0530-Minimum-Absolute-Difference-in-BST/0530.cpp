static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int getMinimumDifference(TreeNode* root) 
    {
        res = INT_MAX, pre = nullptr;
        inOrder(root);
        return res;
    }
private:
    int res;
    int *pre;
    
    void inOrder(TreeNode* root)
    {
        if (root != nullptr)
        {
            inOrder(root->left);
            if (pre != nullptr) res = min(res, root->val - *pre);
            pre = &(root->val);
            inOrder(root->right);
        }
    }
};