#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int pre1 = 0, cur1 = 0, pre2 = 0, cur2 = 0;
        for (unsigned int i = 0; i < nums.size() - 1; ++i)
        {
            int tmp = pre1;
            pre1 = cur1;
            cur1 = max(tmp + nums[i], cur1);
        }
        for (unsigned int i = 1; i < nums.size(); ++i)
        {
            int tmp = pre2;
            pre2 = cur2;
            cur2 = max(tmp + nums[i], cur2);
        }
        return max(cur1, cur2);
    }
};
int main()
{    
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << Solution().rob(nums);
}