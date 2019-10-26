class Solution 
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<vector<int> > res;
        vector<pair<int, int> > points;

        for(const auto& it : buildings)
        {
            points.push_back({it[0], -it[2]});
            points.push_back({it[1], it[2]});
        }

        sort(points.begin(), points.end());
        multiset<int> height = {0};
        int preHighest = 0;
        int curHighest = 0;
        for(const auto& co : points)
        {
            if(co.second < 0) height.insert(-co.second);
            else height.erase(height.find(co.second));
            curHighest = *height.rbegin();
            if(preHighest != curHighest)
            {
                res.push_back({co.first, curHighest});
                preHighest = curHighest;
            }
        }
        return res;
    }
};