#include <algorithm>
#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        string x_str = to_string(x);
        return equal(x_str.begin(), x_str.begin() + x_str.size()/2, x_str.rbegin());
    }
};