static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if (root == nullptr) return {};
        vector<int> res;
        deque<TreeNode*> s;
        s.push_back(root);
        
        while (!s.empty()) 
        {
            int n = s.size();
            res.push_back(s.back()->val);
            for (int i = 0; i < n; ++i) 
            {
                TreeNode* node = s.front(); s.pop_front();
                if (node->left) s.push_back(node->left);
                if (node->right) s.push_back(node->right);
            }
        }
        return res;
    }
};