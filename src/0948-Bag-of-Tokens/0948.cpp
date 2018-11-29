#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int bagOfTokensScore(vector<int>& tokens, int P) 
    {
        int res = 0, cur = 0, i = 0, j = tokens.size()-1;
        sort(tokens.begin(), tokens.end());
        while (i <= j and cur >= 0)
        {
            if (tokens[i] <= P)
            {
                P -= tokens[i++]; 
                res = max(res, ++cur);
            }
            else 
            {
                P += tokens[j--];
                cur--;
            }
        }
        return res;
    }
};
