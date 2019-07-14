class Solution 
{
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) 
    {
        int mCnt = 0;
        unordered_map<int, int> counts;

        for (int c : nums) 
        {
            counts[c]++;
            mCnt = max(mCnt, counts[c]);
        }
        
        return mCnt * K > nums.size() ? false : true;
    }
};