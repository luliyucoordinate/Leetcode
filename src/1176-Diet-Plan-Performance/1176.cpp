class Solution 
{
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper)
    {
        int cnt = accumulate(calories.begin(), calories.begin() + k, 0);
        int res = (cnt > upper) - (cnt < lower);
        for (int i = k; i < calories.size(); ++i)
        {
            cnt += calories[i] - calories[i - k];
            res += (cnt > upper) - (cnt < lower);
        }
        return res;
    }
};