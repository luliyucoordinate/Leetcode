class Solution 
{
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        vector<int> d;
        for (int i = 0; i < s.size(); i++) d.push_back(abs(s[i] - t[i]));
        int l = 0, r = 0;
        for (; r < s.size(); r++)
        {
            maxCost -= d[r];
            if (maxCost < 0) maxCost += d[l++];
        }
        return r - l;
    }
};