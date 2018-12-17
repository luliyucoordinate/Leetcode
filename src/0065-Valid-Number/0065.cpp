#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isNumber(string s) 
    {
        int i = 0, j = s.size() - 1;
        while (s[i] == ' ') ++i;
        while (s[j] == ' ') --j;
        s = s.substr(i, j - i + 1);
        bool e = false, point = false, num = false;
        i = 0;
        if (s.size() > 0 and (s[i] == '+' or s[i] == '-')) i += 1;
        for (;i < s.size(); ++i)
        {
            char c = s[i];
            if (c <= '9' and c >= '0') 
            {
                num = true;
                continue;
            }
            else if (c == 'e' or c == 'E')
            {
                if (!num or e or i == s.size() - 1) return false;
                e = true;
                if ((s[i + 1] == '-' or s[i + 1] == '+') and i < s.size() - 2) ++i;
            }
            else if (c == '.')
            {
                if (point or e) return false;
                point = true;
            }
            else return false;
        }
        return num;
    }
};