class Solution 
{
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) 
    {
        vector<vector<int>> res;
        int y = 1000;
        for (int x = 1; x <= 1000; ++x) 
        {
            while (y > 1 && customfunction.f(x,y) > z) y--;
            if (customfunction.f(x,y) == z)
                res.push_back({x, y});
        }
        return res;
    }
};