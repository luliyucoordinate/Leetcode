#include <string>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    int myAtoi(string str) 
    {
        long res = 0;
        int neg = 1, ind = str.find_first_not_of(' ');
        
        if (str[ind] == '+' || str[ind] == '-') neg = str[ind++] == '+' ? 1 : -1;
        
        while (ind < str.length() && isdigit(str[ind])) 
        {
            res = res * 10 + (str[ind++] - '0');
            if (res > INT_MAX) return neg == -1 ? INT_MIN : INT_MAX;
        }
        
        return res * neg;
    }
};