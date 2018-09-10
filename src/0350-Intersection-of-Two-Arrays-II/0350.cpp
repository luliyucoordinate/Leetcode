#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> record;
        vector<int> result;
        for (auto& num : nums1) ++record[num];
        for (auto& num : nums2)
        {
            if (record[num] > 0)
            {
                result.push_back(num);
                --record[num];
            }
        }
        return result;
    }
};
int main()
{
    vector<int> nums1 = { 1, 2, 2, 1 };
    vector<int> nums2 = { 2, 2 };
    vector<int> result = Solution().intersect(nums1, nums2);
    for (auto& i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}