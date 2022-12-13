class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& A) {
    int r = A.size(), c = A[0].size();
    for (int i = r - 1; i; i--) {
      for (int j = 0; j < c; j++) {
        int cur = A[i][j];
        if (j) cur = min(cur, A[i][j - 1]);
        if (j < c - 1) cur = min(cur, A[i][j + 1]);
        A[i - 1][j] += cur;
      }
    }
    return *min_element(A[0].begin(), A[0].end());
  }
};