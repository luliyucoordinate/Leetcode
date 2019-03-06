static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        stack<TreeNode*> s1, s2;
        s1.push(root1); s2.push(root2);
        while (!s1.empty() && !s2.empty())
        {
            if (dfs(s1) != dfs(s2)) return false;
        }
        return s1.empty() && s2.empty();
    }
private:
    int dfs(stack<TreeNode*>& s) 
    {
        while (true) 
        {
            TreeNode* node = s.top(); s.pop();
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
            if (!node->left && !node->right) return node->val;
        }
    }
};