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
        int cnt = 0, res = 0;
        for (int num : nums) 
        {
            if (cnt == 0) 
            {
                res = num; ++cnt;
            }
            else if (num == res) ++cnt;
            else --cnt;
        }
        return res;
    }
};
int main()
{    
    vector<int> numbers = {2, 7, 11, 15, 2, 2, 2};
    cout << Solution().majorityElement(numbers);

    return 0;
}