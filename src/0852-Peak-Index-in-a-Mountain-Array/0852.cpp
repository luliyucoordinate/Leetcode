#include <iostream>
#include <vector>
using  namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {
        int l = 0, r = A.size() - 1;
        while (l < r)
        {
            int mid = (r - l)/2 + l;
            if (A[mid] <= A[mid + 1]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
int main()
{
    vector<int> A = {1, 1, 1, 1, 1};
    cout << Solution().peakIndexInMountainArray(A);
    return 0;
}
