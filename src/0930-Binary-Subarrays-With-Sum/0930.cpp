#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numSubarraysWithSum(vector<int>& A, int S) 
    {
        vector<int> zeros;
        int result = 0, cnt = 0;
        if (A.empty()) return result;
        for (auto num : A)
        {
            if (num) 
            {
                zeros.push_back(cnt); cnt = 0;
            }
            else cnt++;
        }
        zeros.push_back(cnt);
        if (S)
        {
            for (unsigned int i = 0; i < zeros.size() - S; ++i)
            {
                result += (zeros[i] + 1) * (zeros[i + S] + 1);
            }
            return result;
        }
        if (S == 0)
        {
            for (unsigned int i = 0; i < zeros.size(); ++i)
            {
                if (zeros[i]) result += (zeros[i] + 1)*zeros[i];
            }
            result /= 2;
            return result;
        }
    }
};
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int k = 3;
    cout << Solution().numSubarraysWithSum(nums, k);
    return 0;
}
