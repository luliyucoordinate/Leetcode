#include <iostream>
#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    char findTheDifference(string s, string t) 
    {
        char result = 0;
        for (auto ch : s) result ^= ch;
        for (auto ch : t) result ^= ch;
        return result;
    }
};

int main()
{
    string s = "abcd";
    string t = "abcde";
    cout << Solution().findTheDifference(s, t);
    return 0;
}   