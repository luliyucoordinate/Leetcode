class Solution {
 public:
  bool squareIsWhite(string coordinates) {
    return (coordinates[0] - 'a' + coordinates[1] - '1') & 1;
  }
};