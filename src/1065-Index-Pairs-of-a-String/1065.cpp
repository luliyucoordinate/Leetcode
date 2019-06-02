class Solution 
{
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) 
    {
        vector<vector<int>> res;
        for (int i = 0; i < text.size(); i++) 
        {
            for (auto& x : words) 
            {
                if (text.size() - i >= x.size() && x == text.substr(i, x.size()))
                    res.push_back({i, i + x.size() - 1});
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};