#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        if (nums_set.size() == nums.size())
        {
            return false;
        }
        return true;
    }
};
int main()
{
    vector<int> nums = {1,0,1,1};
    cout << Solution().containsDuplicate(nums);
    return 0;
}