class Solution {
 public:
  bool checkXMatrix(vector<vector<int>>& grid) {
    bool res = true;
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j || i + j == n - 1)
          res &= grid[i][j] != 0;
        else
          res &= grid[i][j] == 0;
      }
    }
    return res;
  }
};