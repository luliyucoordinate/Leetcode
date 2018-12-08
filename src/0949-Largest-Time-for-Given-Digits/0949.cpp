#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    string largestTimeFromDigits(vector<int>& A) 
    {
      sort(begin(A), end(A), greater<int>());
      do 
      {
          if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6) 
          return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
      }
      while (prev_permutation(begin(A), end(A)));
      return "";
    }
};