class Solution {
 public:
  long long putMarbles(vector<int>& weights, int k) {
    int n = weights.size();
    for (int i = 0; i < n - 1; i++) weights[i] += weights[i + 1];
    sort(weights.begin(), weights.end() - 1);
    long long res = 0;
    for (int i = 0; i < k - 1; i++) {
      res += weights[n - i - 2] - weights[i];
    }
    return res;
  }
};