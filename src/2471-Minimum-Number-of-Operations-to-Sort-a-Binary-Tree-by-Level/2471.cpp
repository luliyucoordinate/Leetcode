class Solution {
 public:
  int minimumOperations(TreeNode* root) {
    vector<TreeNode*> q1{root};
    int res = 0;
    while (q1.size()) {
      vector<TreeNode*> q2;
      vector<int> values;
      for (auto& node : q1) {
        values.emplace_back(node->val);
        if (node->left) {
          q2.emplace_back(node->left);
        }
        if (node->right) {
          q2.emplace_back(node->right);
        }
      }

      vector<bool> vis(q1.size());
      vector<int> ids(q1.size());
      iota(ids.begin(), ids.end(), 0);
      sort(ids.begin(), ids.end(),
           [&](int i, int j) { return values[i] < values[j]; });

      res += q1.size();
      for (auto v : ids) {
        if (vis[v]) {
          continue;
        }

        while (!vis[v]) {
          vis[v] = true;
          v = ids[v];
        }
        res--;
      }
      swap(q1, q2);
    }
    return res;
  }
};