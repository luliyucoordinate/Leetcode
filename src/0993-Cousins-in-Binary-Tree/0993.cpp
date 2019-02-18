static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int d = 0, xd = -1, yd = -2;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode* node = q.front(); q.pop();
                if (node->val == x) xd = d;
                if (node->val == y) yd = d;
                if (node->left and node->right and 
                    (node->left->val == x and node->right->val == y or 
                    node->left->val == y and node->right->val == x)) 
                    return false;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            d++;
        }
        return xd == yd;
    }
};