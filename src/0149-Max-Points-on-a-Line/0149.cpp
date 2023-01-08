class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int res = 1, n = points.size();
    unordered_map<int, int> lines;
    for (int i = 0; i < n; i++) {
      lines.clear();
      for (int j = i + 1; j < n; j++) {
        auto& p1 = points[i];
        auto& p2 = points[j];

        auto a = p1[0] - p2[0];
        auto b = p1[1] - p2[1];
        auto c = GCD(a, b);
        a /= c, b /= c;
        lines[a * 20000 + b]++;
      }
      for (auto& [x, y] : lines) {
        res = max(res, y + 1);
      }
    }
    return res;
  }
  int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }
};