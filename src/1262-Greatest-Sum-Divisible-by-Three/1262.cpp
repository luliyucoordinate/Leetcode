class Solution 
{
public:
    int maxSumDivThree(vector<int>& nums) 
    {
        vector<int> res(3, 0);
        for (int a : nums)
        {
            vector<int> tmp = res;
            for (int i : tmp)
                res[(i + a)%3] = max(res[(i + a)%3], i + a);
        }
        return res[0];
    }
};