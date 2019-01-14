#include <unordered_map>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int findMaxLength(vector<int>& nums)
    {
        int pre_sum = 0, res = 0;
        unordered_map<int, int> dic = {{0, -1}};
        
        for (int i = 0; i < nums.size(); ++i) 
        {
            pre_sum += nums[i] == 0 ? -1 : 1;
            if (dic.count(pre_sum)) res = max(res, i - dic[pre_sum]);
            else dic[pre_sum] = i;
        }
        return res;
    }
};