class Solution {
 public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int d[5] = {0, 1, 0, -1, 0};
    int r = maze.size() - 1, c = maze[0].size() - 1;
    maze[entrance[0]][entrance[1]] = '+';
    queue<array<int, 3>> q;
    q.push({entrance[0], entrance[1], 0});

    while (q.size()) {
      auto p = q.front();
      q.pop();
      if ((p[0] == 0 || p[1] == 0 || p[0] == r || p[1] == c) &&
          (p[0] != entrance[0] || p[1] != entrance[1])) {
        return p[2];
      }

      for (int i = 0; i < 4; i++) {
        int nx = d[i] + p[0], ny = d[i + 1] + p[1];
        if (nx >= 0 && ny >= 0 && nx <= r && ny <= c && maze[nx][ny] == '.') {
          maze[nx][ny] = '+';
          q.push({nx, ny, p[2] + 1});
        }
      }
    }
    return -1;
  }
};