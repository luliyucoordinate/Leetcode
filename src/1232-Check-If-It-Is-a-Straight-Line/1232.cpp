class Solution 
{
public:
    bool checkStraightLine(vector<vector<int>>& c) 
    {
        for (int i = 2; i < c.size(); i++)
        {
            if ((c[i][0] - c[0][0]) * (c[i][1] - c[1][1]) != 
                (c[i][0] - c[1][0]) * (c[i][1] - c[0][1])) 
                return false;
        }
        return true;
    }
};