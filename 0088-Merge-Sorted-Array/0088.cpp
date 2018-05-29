#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int> all_list = nums1;
        for (int i = m; i < n + m; ++i)
        {
            all_list[i] = nums2[i - m];
        }
        int i = 0, j = m;
        for (int k = 0; k < m + n; ++k)
        {
            if (i > m - 1)
            {
                nums1[k] = all_list[j++];
            }
            else if (j > m + n - 1)
            {
                nums1[k] = all_list[i++];
            }
            else if (all_list[i] < all_list[j])
            {
                nums1[k] = all_list[i++];
            }
            else
            {
                nums1[k] = all_list[j++];
            }
        }
    }
};
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int pos = m + n - 1;
        --m; --n;
        while (m >= 0 && n >= 0) 
        {
            if(nums1[m] > nums2[n]) 
                nums1[pos--] = nums1[m--]; 
            else
                nums1[pos--] = nums2[n--];
        }
        while (n >= 0) 
        {
            nums1[pos--] = nums2[n--];
        }
    }
};
int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    Solution().merge(nums1, m, nums2, n);
    for (auto& num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}