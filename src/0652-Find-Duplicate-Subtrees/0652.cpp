class Solution 
{
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        dfs(root);
        return res;
    }
private:
    unordered_map<string, int> m;
    vector<TreeNode*> res;
    
    string dfs(TreeNode* root)
    {
        if (!root) return "";
        string s = to_string(root->val) + "," + dfs(root->left) + "," + dfs(root->right);
        if(m[s]++ == 1) res.push_back(root);
        return s;
    }
};