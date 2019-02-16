static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        mem = vector<vector<int>>(nums.size(), vector<int>(nums.size(), 0));
        return selectNumber(nums, 0, nums.size()-1) >= 0 ? true : false;
    }
private:
    vector<vector<int>> mem;
    
    int selectNumber(vector<int>& nums, int l, int r)
    {
        if (l == r) return nums[l];
        if (mem[l][r] > 0) return mem[l][r];
        mem[l][r] = max(nums[l] - selectNumber(nums, l+1, r), nums[r] - selectNumber(nums, l, r-1));
        return mem[l][r];
    }
};