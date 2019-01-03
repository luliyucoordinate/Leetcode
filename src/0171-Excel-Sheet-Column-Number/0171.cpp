#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int titleToNumber(string s) 
    {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) result = result * 26 + (s[i] - 64);
        return result;
    }
};