class Solution 
{
public:
    vector<vector<int>> groupThePeople(vector<int>& a) 
    {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> data;
        for (int i = 0; i < a.size(); i++) 
        {
            data[a[i]].push_back(i);
            if (data[a[i]].size() == a[i]) 
            {
                res.push_back(data[a[i]]);
                data[a[i]].clear();
            }
        }
        return res;
    }
};