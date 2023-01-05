class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
         [](auto& u, auto& v) { return u[1] < v[1]; });
    int i = points[0][1];
    int res = 1;
    for (auto& point : points) {
      if (point[0] > i) {
        i = point[1];
        ++res;
      }
    }
    return res;
  }
};
