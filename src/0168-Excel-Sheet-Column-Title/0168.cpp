static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    string convertToTitle(int n) 
    {
        string res = "";
        while (n)
        {
            res = (char)('A' + --n%26) + res;
            n /= 26;
        }
        return res;
    }
};