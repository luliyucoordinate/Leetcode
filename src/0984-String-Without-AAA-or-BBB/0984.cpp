#include <string>
#include <iostream>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    string strWithout3a3b(int A, int B, char a='a', char b='b') 
    {
        if (B > A) return strWithout3a3b(B, A, b, a);
        if (B == 0) return string(A, a);
        return string(A > B ? 2 : 1, a) + b + strWithout3a3b(A - (A > B ? 2 : 1), B - 1, a, b);
    }
};