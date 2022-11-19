class Solution {
 public:
  int largestAltitude(vector<int>& gain) {
    int res = 0, cur = 0;
    for (auto& x : gain) {
      cur += x;
      res = max(res, cur);
    }
    return res;
  }
};