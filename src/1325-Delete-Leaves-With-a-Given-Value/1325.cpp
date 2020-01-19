class Solution 
{
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        if (root == nullptr) return nullptr;
        root->left = removeLeafNodes(root->left, target);
        root->right =removeLeafNodes(root->right, target);
        return root->val == target && root->left == root->right ? nullptr : root;
    }
};