#include <sstream>
#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int compareVersion(string version1, string version2) 
    {
        istringstream is1(version1);
        istringstream is2(version2);
        int num1 = 0, num2 = 0;
        char c;
        while( bool(is1 >> num1) + bool(is2 >> num2)) 
        {
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;
            is1 >> c; is2 >> c;
            num1 = num2 = 0;
        }
        return 0;
    }
};