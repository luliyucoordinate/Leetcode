#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minAddToMakeValid(string S) 
    {
        int right= 0, left = 0;
        for (auto& s : S)
        {
            s == '(' ? ++left: --left;
            if (left == -1) 
            {
                ++right; ++left;
            }
        }
        return right + left;
    }
};
int main()
{
    string S = "";
    cout << Solution().minAddToMakeValid(S);
    return 0;
}