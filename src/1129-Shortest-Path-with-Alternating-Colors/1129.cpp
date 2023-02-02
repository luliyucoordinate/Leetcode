class Solution {
 public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges,
                                       vector<vector<int>>& blue_edges) {
    vector<vector<vector<int>>> g(2, vector<vector<int>>(n));
    for (auto& e : red_edges) g[0][e[0]].push_back(e[1]);
    for (auto& e : blue_edges) g[1][e[0]].push_back(e[1]);
    vector<vector<bool>> vis(2, vector<bool>(n));

    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({1, 0});

    vector<int> res(n, -1);
    int d = 0;
    while (!q.empty()) {
      auto qs = q.size();
      while (qs--) {
        auto [x, y] = q.front();
        q.pop();
        vis[x][y] = true;
        auto c = 1 - x;
        for (auto& v : g[c][y]) {
          if (vis[c][v]) continue;
          q.push({c, v});
        }
        if (res[y] == -1) res[y] = d;
      }
      d++;
    }

    return res;
  }
};