class Solution 
{
public:
    bool findTarget(TreeNode* root, int k) 
    {
        if (!root) return false;
        if (seen.count(k - root->val)) return true;
        seen.insert(root->val);
        return findTarget(root->left, k) or findTarget(root->right, k);
    }
private:
    unordered_set<int> seen;
};