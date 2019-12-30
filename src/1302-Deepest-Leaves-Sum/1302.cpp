class Solution 
{
public:
    int deepestLeavesSum(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        
        while (!q.empty())
        {
            int n = q.size();
            res = 0;
            
            while (n--)
            {
                auto cur = q.front(); q.pop();
                res += cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }
};