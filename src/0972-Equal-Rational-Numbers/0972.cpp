#include <string>

using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isRationalEqual(string S, string T) 
    {
        return toNumber(S) == toNumber(T);
    }

private:
    double toNumber(string S) 
    {
        auto i = S.find("(");
        if (i != string::npos) 
        {
            string base = S.substr(0, i);
            string rep = S.substr(i + 1, S.length() - i - 2);
            for (int j = 0; j < 20; ++j) base += rep;
            return stod(base);
        }
        return stod(S);
    }
};