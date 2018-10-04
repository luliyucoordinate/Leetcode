#include <iostream>
#include <vector>
using  namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int sum = 0;
        for (auto& i : nums) sum += i;
        if (sum < S or (S + sum) %2 != 0) return 0;

        int target = (S + sum) >> 1;
        vector<int> mem(target + 1, 0);
        mem[0] = 1;
        for (auto& num : nums)
        {
            for (int i = target; i >= num; --i)
                mem[i] += mem[i - num];
        }
        return mem[target];
    }
};
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int S = 3;
    cout << Solution().findTargetSumWays(nums, S);
    return 0;
}
