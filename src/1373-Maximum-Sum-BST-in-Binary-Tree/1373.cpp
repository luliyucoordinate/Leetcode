class Solution 
{
public:
    int maxSumBST(TreeNode* root) 
    {
        dfs(root);
        return maxv;
    }
private:
    int maxv = 0;
    
    pair<int, int> dfs(TreeNode* root)
    {
        if (root == nullptr) return {true, 0};
        
        pair<int, int> res = {true, root->val};
        if (root->left != nullptr)
        {
            auto left = dfs(root->left);
            if (left.first && root->left->val < root->val) res.second += left.second;
            else res.first = false;
        }
        if (root->right != nullptr)
        {
            auto right = dfs(root->right);
            if (right.first && root->right->val > root->val) res.second += right.second;
            else res.first = false;
        }
        
        if (res.first) maxv = max(maxv, res.second);
        return res;
    }
};