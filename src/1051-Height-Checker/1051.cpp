class Solution 
{
public:
    int heightChecker(vector<int>& heights) 
    {
        int res = 0;
        vector<int> tmp(heights);
        sort(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); ++i) 
        {
            if (heights[i] != tmp[i]) ++res;
        }
        return res;
    }
};