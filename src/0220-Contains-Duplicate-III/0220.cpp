
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        set<long long> record;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (record.lower_bound((long long)nums[i] - (long long)t) != record.end() && 
                    *record.lower_bound((long long)nums[i] - (long long)t) <= (long long)nums[i] + (long long)t)
                return true;
            record.insert(nums[i]);
            if (record.size() == k + 1)
            {
                record.erase(nums[i - k]);
            } 
        }
        return false;
    }
};
int main()
{
    vector<int> nums = {1,2,3,1};
    int k = 4;
    int t = 0;
    cout << Solution().containsNearbyAlmostDuplicate(nums, k, t);
    return 0;
}