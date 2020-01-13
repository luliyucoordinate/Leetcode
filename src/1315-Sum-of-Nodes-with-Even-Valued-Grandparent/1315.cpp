class Solution 
{
public:
    int sumEvenGrandparent(TreeNode* root) 
    {
        return dfs(root, 1, 1);
    }
    
    int dfs(TreeNode* root, int p, int gp)
    {
        if (root == nullptr) return 0;
        return dfs(root->left, root->val, p) + 
            dfs(root->right, root->val, p) + 
            (gp % 2 == 0 ? root->val : 0);
    }
};