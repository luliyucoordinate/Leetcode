#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int ones = 0, twos = 0;
        for (auto num : nums)
        {
            ones = (ones^num) & ~twos;
            twos = (twos^num) & ~ones;
        }
        return ones;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {2,2,2,1};
    cout << Solution().singleNumber(nums);
    return 0;
}