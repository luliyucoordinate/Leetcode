class Solution {
 public:
  int countBalls(int lowLimit, int highLimit) {
    vector<int> cnt(46, 0);
    int res = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
      int cur = i, t = 0;
      while (cur) {
        t += cur % 10;
        cur /= 10;
      }
      cnt[t]++;
      res = max(res, cnt[t]);
    }
    return res;
  }
};