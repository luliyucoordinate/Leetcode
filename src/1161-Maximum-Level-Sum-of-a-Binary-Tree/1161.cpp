class Solution 
{
public:
    int maxLevelSum(TreeNode* root) 
    {
        if (!root)   return 0;
        queue<TreeNode*> q; q.push(root);
        int maxSum = 0, res = 0, level = 0;
        
        while (q.size())
        {
            int curSum = 0, qLen = q.size();
            for (int i = 0; i < qLen; ++i)
            {
                auto node = q.front(); q.pop();
                curSum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            level++;
            if (curSum > maxSum) 
            {
                maxSum = curSum;
                res = level;
            }
        }
        return res;
    }
};