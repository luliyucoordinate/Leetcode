#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (record.count(nums[i]) && (i - record[nums[i]]) <= k)
            {
                return true;
            }
            record[nums[i]] = i;
        }
        return false;
    }
};
int main()
{
    vector<int> nums = {1,0,1,1};
    int k = 1;
    cout << Solution().containsNearbyDuplicate(nums, k);
    return 0;
}