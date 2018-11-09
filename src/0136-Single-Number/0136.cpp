#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int result = 0;
        for (auto num : nums) result ^= num;
        return result;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {2,2,1};
    cout << Solution().singleNumber(nums);
    return 0;
}