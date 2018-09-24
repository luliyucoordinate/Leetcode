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
        int pre = 0;
        int cur = 0;
        for (auto& i : nums)
        {
            int tmp = pre;
            pre = cur;
            cur = max(tmp + i, cur);
        }
        return cur;
    }
};
int main()
{    
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << Solution().rob(nums);
}