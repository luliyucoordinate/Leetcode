class Solution 
{
public:
    vector<int> decompressRLElist(vector<int>& nums) 
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2)
        {
            res.insert(res.end(), nums[i], nums[i + 1]);
        }
        return res;
    }
};