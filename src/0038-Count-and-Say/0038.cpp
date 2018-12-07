#include <string>
static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();

class Solution 
{
public:
    string countAndSay(int n) 
    {
        string res = "1";
        for (int i = 1; i < n; ++i)
        {
            res = count(res);
        }
        return res;
    }
private:
    string count(string& str)
    {
        string res;
        int c = 1;
        for (int i = 1; i < str.size(); ++i)
        {
            if (str[i] != str[i - 1])
            {
                res += to_string(c) + str[i - 1];
                c = 0;
            }
            ++c;
        }
        return res + to_string(c) + *(str.rbegin());
    }
};