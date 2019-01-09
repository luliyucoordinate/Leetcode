#include <numeric>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class NumArray 
{
public:
    NumArray(vector<int> nums) : _nums(nums.size()+1, 0) 
    {
        partial_sum(nums.begin(), nums.end(), _nums.begin()+1);
    }
    
    int sumRange(int i, int j) 
    {
        return _nums[j+1] - _nums[i];
    }
private:
    vector<int> _nums;
};