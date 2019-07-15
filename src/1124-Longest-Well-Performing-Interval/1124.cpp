class Solution 
{
public:
    int longestWPI(vector<int>& hours) 
    {
        int res = 0, pre_sum = 0;
        unordered_map<int, int> seen;
        for (int i = 0; i < hours.size(); ++i)
        {
            pre_sum += hours[i] > 8 ? 1 : -1;
            if (!seen.count(pre_sum)) seen[pre_sum] = i;
            if (pre_sum > 0) res = i + 1;
            else if (seen.count(pre_sum - 1)) res = max(res, i - seen[pre_sum - 1]);
        }
        return res;
    }
};