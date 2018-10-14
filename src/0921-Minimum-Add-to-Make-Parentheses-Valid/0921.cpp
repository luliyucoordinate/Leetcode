#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minAddToMakeValid(string S) 
    {
        int result= 0, tmp = 0;
        for (auto& s : S)
        {
            s == '(' ? ++tmp: --tmp;
            if (tmp == -1) 
            {
                ++result; ++tmp;
            }
        }
        return result + tmp;
    }
};
int main()
{
    string S = "";
    cout << Solution().minAddToMakeValid(S);
    return 0;
}