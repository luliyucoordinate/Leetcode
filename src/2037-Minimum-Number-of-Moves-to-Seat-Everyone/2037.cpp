class Solution {
 public:
  int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int res = 0;
    for (int i = seats.size() - 1; ~i; i--) {
      res += abs(seats[i] - students[i]);
    }
    return res;
  }
};