class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return sortedToBST(0, res.size() - 1);
    }
    
private:
    vector<int> res;
    
    void inOrder(TreeNode* root) {
        if (root != nullptr) {
            inOrder(root->left);
            res.emplace_back(root->val);
            inOrder(root->right);
        }
    }
    
    TreeNode* sortedToBST(int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        TreeNode* root = new TreeNode(res[mid]);
        root->left = sortedToBST(l, mid - 1);
        root->right = sortedToBST(mid + 1, r);
        return root;
    }
};