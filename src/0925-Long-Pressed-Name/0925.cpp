#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isLongPressedName(string name, string typed) 
    {
        int i = 0, m = name.length(), n = typed.length();
        for (unsigned int j = 0; j < n; ++j)
            if (i < m and name[i] == typed[j])
                ++i;
            else if (j == 0 or typed[j] != typed[j - 1])
                return false;

        return i == m;
    }
};
int main()
{
    string name = "alex";
    string typed = "aaleex";
    cout << Solution().isLongPressedName(name, typed);
    return 0;
}