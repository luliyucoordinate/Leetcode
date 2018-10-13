#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if (nums.empty()) return 1;
        int max_len = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> mem(max_len, 0);
        mem[0] = 1;
        for (auto& num : nums)
        {
            if (num > 0) mem[num] = 1;
        }
        for (unsigned int i = 0; i < mem.size(); ++i)
        {
            if (mem[i] != 1) return i;
        }
        return max_len;
    }
};
int main()
{
    vector<int> nums = {3,4,-1,1};
    cout << Solution().firstMissingPositive(nums);
    return 0;
}
