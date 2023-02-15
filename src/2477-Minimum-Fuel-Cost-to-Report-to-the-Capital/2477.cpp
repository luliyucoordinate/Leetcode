class Solution {
 public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    int n = roads.size();
    vector<vector<int>> m(n + 1);
    for (auto& x : roads) {
      m[x[0]].push_back(x[1]);
      m[x[1]].push_back(x[0]);
    }

    long long res = 0;
    function<int(int, int)> dfs = [&](int u, int fa) {
      int x = 1;
      for (auto v : m[u]) {
        if (v != fa) x += dfs(v, u);
      }
      if (u) res += (x + seats - 1) / seats;
      return x;
    };

    dfs(0, -1);
    return res;
  }
};