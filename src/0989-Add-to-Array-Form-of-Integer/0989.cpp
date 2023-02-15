class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> res;
    for (int i = num.size() - 1; ~i; i--) {
      k += num[i];
      res.push_back(k % 10);
      k /= 10;
    }
    while (k) res.push_back(k % 10), k /= 10;
    reverse(res.begin(), res.end());
    return res;
  }
};