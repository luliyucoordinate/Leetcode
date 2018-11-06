#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
int main()
{    
    vector<int> numbers = {2, 7, 11, 15, 2, 2, 2};
    cout << Solution().majorityElement(numbers);

    return 0;
}