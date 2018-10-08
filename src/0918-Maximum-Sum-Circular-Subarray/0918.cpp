#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& A) 
    {
        if (A.empty()) return 0;
        int total = 0, max_result = A[0], cur_max = 0, min_result = A[0], cur_min = 0;
        for (unsigned int i = 0; i < A.size(); i++) 
        {
            total += A[i];
            max_result = max(max_result, cur_max = A[i] + max(0, cur_max));
            min_result = min(min_result, cur_min = A[i] + min(0, cur_min));
        }
        return max_result < 0 ? max_result : max(max_result, total - min_result);
    }
};
int main()
{
    vector<int> A = {-2,-3,-1};
    cout << Solution().maxSubarraySumCircular(A);
    return 0;
}
