class Solution 
{
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) 
    {
        map<int, vector<int>> m;
        for (auto& it : items) m[it[0]].push_back(it[1]);
        vector<vector<int>> res;
        for (auto& it : m) 
        {
            sort(it.second.begin(), it.second.end(), greater<int>());
            res.push_back({it.first, accumulate(it.second.begin(), it.second.begin()+5, 0)/5});
        }
        return res;
    }
};