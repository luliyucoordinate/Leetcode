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
        int max_A = *max_element(A.begin(), A.end());
        if (max_A < 0) return max_A;
        int result1 = kadane(A);
        int result2 = 0;
        for (unsigned int i = 0; i < A.size(); ++i)
        {
            result2 += A[i];
            A[i] = -A[i];
        }
        result2 += kadane(A);
        return max(result1, result2);
    }
private:
    int kadane(vector<int>& nums)
    {
        int cur = 0, result = 0;
        for (auto& num :nums)
        {
            cur += num;
            if (cur < 0) cur = 0;
            if (result < cur) result = cur;
        }
        return result;
    }
};
int main()
{
    vector<int> A = {-2,-3,-1};
    cout << Solution().maxSubarraySumCircular(A);
    return 0;
}
