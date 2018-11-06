#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        vector<int> result(nums);
        for (unsigned int i = 0; i < nums.size(); ++i)
        {
            nums[(i+k)%nums.size()] = result[i];
        }
    }
};
int main()
{    
    vector<int> nums = {2, 7, 11, 15, 2, 2, 2};
    int k = 3;
    Solution().rotate(nums, k);
    for (auto& num : nums)
    {
        cout << num << " ";
    }
    return 0;
}