class Solution {
 public:
  vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    int n = trees.size();
    if (n < 4) return trees;

    vector<vector<int>> res;
    sort(trees.begin(), trees.end());

    vector<int> ids = {0};
    vector<bool> used(n, false);
    for (int i = 1; i < n; i++) {
      while (ids.size() > 1 && cross(trees[ids[ids.size() - 2]],
                                     trees[ids.back()], trees[i]) < 0) {
        used[ids.back()] = false;
        ids.pop_back();
      }
      ids.push_back(i);
      used[i] = true;
    }

    for (int i = n - 2, t = ids.size(); ~i; i--) {
      if (used[i]) continue;
      while (ids.size() > t && cross(trees[ids[ids.size() - 2]],
                                     trees[ids.back()], trees[i]) < 0) {
        used[ids.back()] = false;
        ids.pop_back();
      }
      ids.push_back(i);
      used[i] = true;
    }
    ids.pop_back();
    for (auto& id : ids) {
      res.push_back(trees[id]);
    }
    return res;
  }

  int cross(vector<int>& p, vector<int>& q, vector<int>& r) {
    return (q[0] - p[0]) * (r[1] - q[1]) - (r[0] - q[0]) * (q[1] - p[1]);
  }
};