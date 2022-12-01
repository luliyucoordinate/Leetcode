class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int n = points.size();
    int d = INT_MAX;
    int res = -1;
    for (int i = 0; i < n; i++) {
      auto& p = points[i];
      if (x == p[0] || y == p[1]) {
        auto c = abs(x - p[0]) + abs(y - p[1]);
        if (c == 0) {
          return i;
        } else if (c < d) {
          res = i;
          d = c;
        }
      }
    }
    return res;
  }
};