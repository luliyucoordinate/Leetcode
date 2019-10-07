class Solution 
{
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) 
    {
        if (!root1) return false;
        if (find(root2, target - root1->val)) return true;
        return twoSumBSTs(root1->left, root2, target) or
            twoSumBSTs(root1->right, root2, target);
    }
    
private:
    bool find(TreeNode* root, int target)
    {
        if (!root) return false;
        if (target == root->val) return true;
        else if (target < root->val) return find(root->left, target);
        else return find(root->right, target);
    }
};