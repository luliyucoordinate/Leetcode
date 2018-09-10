#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> record(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for (auto& i : nums2)
        {
            if (record.count(i) != 0) result.insert(i);
        }
        return vector<int>(result.begin(), result.end());
    }
};
int main()
{
    vector<int> nums1 = { 1, 2, 2, 1 };
    vector<int> nums2 = { 2, 2 };
    vector<int> result = Solution().intersection(nums1, nums2);
    for (auto& i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}