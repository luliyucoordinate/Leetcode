static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
  public:
    void dfs(TreeNode *r, int x, int y, map<int, map<int, set<int>>> &m)
    {
        if (r != nullptr)
        {
            m[x][y].insert(r->val);
            dfs(r->left, x - 1, y + 1, m);
            dfs(r->right, x + 1, y + 1, m);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode *r)
    {
        map<int, map<int, set<int>>> m;
        dfs(r, 0, 0, m);
        vector<vector<int>> res;
        for (auto itx = m.begin(); itx != m.end(); ++itx)
        {
            res.push_back(vector<int>());
            for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity)
            {
                res.back().insert(end(res.back()), begin(ity->second), end(ity->second));
            }
        }
        return res;
    }
};