#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int pre = -1, cur = 0, step = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cur >= nums.size() - 1) return step;
            if (pre < i && i <= cur)
            {
                step++, pre = cur;
            }
            cur = max(cur, i + nums[i]);
        }
        return step;
    }
};

int main()
{
    vector<int> nums = {3,4,-1,1};
    cout << Solution().jump(nums);
    return 0;
}
