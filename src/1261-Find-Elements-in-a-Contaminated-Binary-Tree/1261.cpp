class FindElements 
{
public:
    FindElements(TreeNode* root) 
    {
        root->val = 0;
        data.insert(0);
        dfs(root);
    }
    
    bool find(int target) 
    {
        return data.count(target);
    }
    
private:
    unordered_set<int> data;
    
    void dfs(TreeNode* root) 
    {
        if (root->left) 
        {
            root->left->val = 2 * root->val + 1;
            data.insert(root->left->val);
            dfs(root->left);
        }
        if (root->right)
        {
            root->right->val = 2 * root->val + 2;
            data.insert(root->right->val);
            dfs(root->right);
        }
    }
};