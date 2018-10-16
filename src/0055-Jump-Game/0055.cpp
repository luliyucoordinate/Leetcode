#include <iostream>
#include <vector>
using namespace std;


static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int m = 0;
        for (uint i = 0; i < nums.size(); ++i)
        {
            if (i > m) return false;
            if (m < i + nums[i]) m = i + nums[i];
        }
        return true;
    }
};
int main()
{
    vector<int> nums = {2,3,1,1,4};
    cout << Solution().canJump(nums);
}