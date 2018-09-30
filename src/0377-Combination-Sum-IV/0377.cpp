#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<int> mem(target + 1, 0);
        mem[0] = 1;
        for(int i = 1; i <= mem.size(); i++)
        {
            for (auto& num : nums)
            {
                if (i >= num) mem[i] += mem[i - num];
            }
        }
        return *mem.rbegin();
    }
};

int main()
{
    vector<int> nums = {1, 2, 4};
    int target = 32;
    cout << Solution().combinationSum4(nums, target);
    return 0;
}