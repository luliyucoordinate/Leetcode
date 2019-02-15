static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> res;
        vector<TreeNode*> cur, next;
        cur.push_back(root);
        while (not cur.empty())
        {
            long long s = 0;
            for (auto it : cur)
            {
                s += it->val;
                if (it->left) next.push_back(it->left);
                if (it->right) next.push_back(it->right);
            }
            res.push_back(static_cast<double>(s)/cur.size());
            cur.swap(next);
            next.clear();
        }
        return res;
    }
};