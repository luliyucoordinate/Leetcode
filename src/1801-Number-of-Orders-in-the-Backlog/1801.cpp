class Solution {
 public:
  int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    priority_queue<array<int, 2>> buy;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>
        sell;
    for (auto& order : orders) {
      auto p = order[0], a = order[1], o = order[2];
      if (o == 0) {
        while (!sell.empty() && a) {
          auto [ps, as] = sell.top();
          if (ps > p) break;
          sell.pop();
          if (a >= as) {
            a -= as;
          } else {
            sell.push({ps, as - a});
            a = 0;
          }
        }
        if (a) {
          buy.push({p, a});
        }
      } else {
        while (!buy.empty() && a) {
          auto [pb, ab] = buy.top();
          if (pb < p) break;
          buy.pop();
          if (a >= ab) {
            a -= ab;
          } else {
            buy.push({pb, ab - a});
            a = 0;
          }
        }
        if (a) {
          sell.push({p, a});
        }
      }
    }
    int res = 0, mod = 1e9 + 7;
    while (!buy.empty()) {
      res = (res + buy.top()[1]) % mod;
      buy.pop();
    }
    while (!sell.empty()) {
      res = (res + sell.top()[1]) % mod;
      sell.pop();
    }
    return res;
  }
};