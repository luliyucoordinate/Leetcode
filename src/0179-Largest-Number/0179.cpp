static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    string largestNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), [](const int a, const int b) {
            string as = to_string(a), bs = to_string(b);
            return as + bs > bs + as;
        });
        
        if (nums[0] == 0) return "0";
        string res;
        for (int j = 0; j < nums.size(); ++j) 
        {
            res += to_string(nums[j]);
        }
        return res;
    }
};