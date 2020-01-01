class Solution 
{
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        queue<int> q1, q2;
        vector<int> res;
        inOrder(root1, q1);
        inOrder(root2, q2);
        
        while (!q1.empty() || !q2.empty())
        {
            if (q1.empty() || (!q2.empty() && q2.front() <= q1.front()))
            {
                res.emplace_back(q2.front());
                q2.pop();
            } 
            else if (q2.empty() || (!q1.empty() && q1.front() < q2.front()))
            {
                res.emplace_back(q1.front());
                q1.pop();
            }
        }
        return res;
    }
private:
    void inOrder(TreeNode* root, queue<int>& q)
    {
        if (root == nullptr) return;
        inOrder(root->left, q);
        q.emplace(root->val);
        inOrder(root->right, q);   
    }
};