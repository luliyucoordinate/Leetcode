#include <string>
#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        unsigned int m = nums1.size(), n = nums2.size();
        unsigned int mid = (m + n + 1)/2;//maybe overflow
        if (m > n) swap(nums1, nums2), swap(m, n);
        
        unsigned int l = 0, r = m;
        while (l <= r)
        {
            unsigned int i = (r - l) / 2 + l;
            unsigned int j = mid - i;
            if (i < m and nums2[j-1] > nums1[i]) l = i + 1;
            else if (i > 0 and nums2[j] < nums1[i - 1]) r = i - 1;
            else 
            {
                int max_left = 0, min_right = 0;
                if (i == 0) max_left = nums2[j-1];
                else if (j == 0) max_left = nums1[i-1];
                else max_left = max(nums1[i-1], nums2[j-1]);

                if (((m+n)&1) == 1) return max_left;

                if (i == m) min_right = nums2[j];
                else if (j == n) min_right = nums1[i];
                else min_right = min(nums1[i], nums2[j]);
                return (min_right + max_left)/2.0;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}