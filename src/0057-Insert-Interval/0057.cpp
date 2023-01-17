class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> res;
    int n = intervals.size(), i = 0;
    while (i < n) {
      auto& a = intervals[i];
      if (a[1] >= newInterval[0]) break;
      res.push_back(a);
      i++;
    }

    int x = newInterval[0], y = newInterval[1];
    while (i < n) {
      auto& a = intervals[i];
      if (a[0] > y) break;
      y = max(y, a[1]);
      x = min(x, a[0]);
      i++;
    }

    res.push_back({x, y});
    while (i < n) {
      res.push_back(intervals[i++]);
    }

    return res;
  }
};