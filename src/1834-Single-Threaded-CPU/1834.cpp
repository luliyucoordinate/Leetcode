class Solution {
 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    for (int i = 0; i < n; i++) {
      tasks[i].push_back(i);
    }
    sort(tasks.begin(), tasks.end());
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>
        q;
    int i = 0, cur = 0;

    vector<int> res;
    while (i < n) {
      if (q.empty() && cur < tasks[i][0]) {
        cur = tasks[i][0];
      }
      while (i < n && tasks[i][0] <= cur) {
        q.push({tasks[i][1], tasks[i][2]});
        i++;
      }
      auto x = q.top();
      q.pop();
      cur += x[0];
      res.push_back(x[1]);
    }
    while (!q.empty()) {
      auto x = q.top();
      q.pop();
      res.push_back(x[1]);
    }
    return res;
  }
};