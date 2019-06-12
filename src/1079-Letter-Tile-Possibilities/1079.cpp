class Solution 
{
public:
    int numTilePossibilities(string tiles) 
    {
        unordered_map<char,int> cnts;
        int res = 0;
        for(auto c : tiles) cnts[c]++;
        function<void()> dfs = [&]() {
            for(auto& c : cnts)
            {
                if (c.second)
                {
                    c.second--;
                    ++res;
                    dfs();
                    c.second++;
                }
            }
        };
        dfs();
        return res - 1;
    }
};