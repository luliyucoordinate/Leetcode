class Solution 
{
public:
    int maxValueAfterReverse(vector<int>& nums) 
    {
        int n = nums.size(), total = 0, res = 0, Hi = 100010, Lj = -100010;
        for (int i = 0; i < n - 1; i++)
        {
            int a = nums[i], b = nums[i + 1];
            total += abs(a - b);
            Hi = min(Hi, max(a, b)), Lj = max(Lj, min(a, b));
            res = max({res, abs(nums[0] - b) - abs(a - b),
                     abs(a - nums.back()) - abs(a - b), 
                      (Lj - Hi) * 2});
        }
        return total + res;
    }
};