class Solution 
{
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) 
    {
        int n = values.size(), res = 0, counts[20001] = {0};
        vector<pair<int, int>> items;
        for (int i = 0; i < n; i++) items.push_back({values[i], labels[i]});
        sort(items.rbegin(), items.rend());
        for (int i = 0; i < n and num_wanted > 0; i++)
        {
            if (counts[items[i].second] < use_limit)
                res += items[i].first, counts[items[i].second]++, num_wanted--;
        }  
        return res;
    }
};