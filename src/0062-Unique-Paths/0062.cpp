#include <iostream>
#include <math.h>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        return int(exp(lgamma(m+n-1)-lgamma(m)-lgamma(n))+0.5);
    }
};

int main()
{
    return 0;
}