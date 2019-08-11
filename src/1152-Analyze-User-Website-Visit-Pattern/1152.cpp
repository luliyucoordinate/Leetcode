class Solution 
{
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) 
    {
        map<vector<string>, set<string>> data;
        int n = username.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j) 
            {
                if (timestamp[i] < timestamp[j] and 
                    username[i] == username[j])
                {
                    for (int k = 0; k < n; ++k)
                    {
                        if (timestamp[j] < timestamp[k] and 
                            username[j] == username[k])
                            data[{website[i], website[j], website[k]}].insert(username[k]);
                    }
                }
            }
        }
        vector<string> res;
        int s = 0;
        for (auto& it : data)
        {
            if (it.second.size() > s)
            {
                res = it.first;
                s = it.second.size();
            }
        }
        return res;
    }
};