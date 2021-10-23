#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int cnt = 0, res = 0;
    for (int num : nums) {
      if (cnt == 0) {
        res = num;
      } 
      cnt += num == res ? 1 : -1;
    }
    return res;
  }
};
int main() {
  vector<int> numbers = {2, 7, 11, 15, 2, 2, 2};
  cout << Solution().majorityElement(numbers);

  return 0;
}