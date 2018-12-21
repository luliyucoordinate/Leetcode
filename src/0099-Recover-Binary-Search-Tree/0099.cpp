static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    void recoverTree(TreeNode* root) 
    {
        TreeNode* cur = root, *pre = nullptr;
        TreeNode* first = nullptr, *second = nullptr;
        vector<TreeNode*> stack;
        while (!stack.empty() or cur != nullptr)
        {
            if (cur != nullptr)
            {
                stack.push_back(cur);
                cur = cur->left;
            }
            else
            {
                auto node = *(stack.rbegin()); stack.pop_back();
                if (pre != nullptr and pre->val >= node->val)
                {
                    if (first == nullptr) first = pre;
                    second = node;
                }
                pre = node;
                cur = node->right;
            }
        }
        swap(first->val, second->val);
    }
};