#include <iostream>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int integerBreak(int n) 
    {
        if (n <= 3) return n - 1;
        unsigned int result = 1;
        while (n > 4)
        {
            n -= 3;
            result *= 3;
        }
        return n * result;
    }
};

int main()
{
    return 0;
}