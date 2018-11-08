#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        long long n = nums.size();
        return n*(n+1)/2 - accumulate(nums.begin(), nums.end(), 0);
    }
};
int main()
{
    vector<int> nums = {3,0,1};
    cout << Solution().missingNumber(nums);
    return 0;
}