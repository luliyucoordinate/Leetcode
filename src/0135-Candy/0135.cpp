#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        vector<int> res(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i-1]) res[i] = res[i-1] + 1;
        }
        for (int i = ratings.size() - 1; i > 0; --i)
        {
            if (ratings[i] < ratings[i-1] and res[i-1] <= res[i]) res[i-1] = res[i] + 1;
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};