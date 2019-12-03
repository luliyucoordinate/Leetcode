class Solution 
{
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) 
    {
        vector<vector<int>> res;
        for (auto& inter : intervals)
        {
            if (inter[0] >= toBeRemoved[1] || inter[1] <= toBeRemoved[0]) res.push_back(inter);
            else 
            {
                if (inter[0] < toBeRemoved[0]) res.push_back({inter[0], toBeRemoved[0]});
                if (inter[1] > toBeRemoved[1]) res.push_back({toBeRemoved[1], inter[1]});
            }
        }
        return res;
    }
};