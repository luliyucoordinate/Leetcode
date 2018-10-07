#include <iostream>
#include <vector>
#include <string>
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
            if (!('a' <= S[l] and S[l] <= 'z') and !('A' <= S[l] and S[l] <= 'Z'))
            {
                ++l;
                continue;
            }
            if (!('a' <= S[r] and S[r] <= 'z') and !('A' <= S[r] and S[r] <= 'Z'))
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
