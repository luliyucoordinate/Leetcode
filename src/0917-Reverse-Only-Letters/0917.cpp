#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using  namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    string reverseOnlyLetters(string S) 
    {
        int l = 0, r = S.size() - 1;
        while (l < r)
        {
            if (!isalpha(S[l]))
            {
                ++l;
                continue;
            }
            if (!isalpha(S[r]))
            {
                --r;
                continue;
            }
            char tmp = S[l];
            S[l++] = S[r];
            S[r--] = tmp;
        }
        return S;
    }
};
int main()
{
    string S = "a-bC-dEf-ghIj";
    cout << Solution().reverseOnlyLetters(S);
    return 0;
}
