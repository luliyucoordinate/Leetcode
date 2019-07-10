class Solution 
{
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        delete_set = unordered_set<int>(to_delete.begin(), to_delete.end());
        preOrder(root, true);
        return res;
    }
private:
    unordered_set<int> delete_set;
    vector<TreeNode*> res;
    
    TreeNode* preOrder(TreeNode* root, bool n_root)
    {
        if (root == nullptr) return nullptr;
        bool root_delete = delete_set.count(root->val) > 0;
        if (!root_delete and n_root) res.push_back(root);
        root->left = preOrder(root->left, root_delete);
        root->right = preOrder(root->right, root_delete);
        return root_delete ? nullptr : root;
    }
};