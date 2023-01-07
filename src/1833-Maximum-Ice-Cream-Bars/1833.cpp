class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    const int n = 1e5 + 10;
    vector<int> sorted_costs(n);
    for (auto& cost : costs) sorted_costs[cost]++;
    int res = 0;
    for (int i = 1; i < n; i++) {
      if (sorted_costs[i]) {
        if (coins < i) return res;
        auto cur = min(sorted_costs[i], coins / i);
        res += cur;
        coins -= cur * i;
      }
    }
    return res;
  }
};