class Solution 
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        map<int, int> m;
        for (auto& it : trips) 
        {
            m[it[1]] += it[0], m[it[2]] -= it[0];
        }
        
        int n = 0;
        for (auto& it : m)
        {
            n += it.second;
            if (n > capacity) return false;
        }
        return true;
    }
};