#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (++digits[i] %= 10) return digits;
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};

int main() {
  vector<int> digits = {0};
  auto result = Solution().plusOne(digits);
  return 0;
}