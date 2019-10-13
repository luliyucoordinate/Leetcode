class Solution 
{
public:
    int balancedStringSplit(string s) 
    {
        int L = 0, res = 0;
        for (char c : s)
        {
            if (c == 'L') L++;
            else L--;
            if (L == 0) res++;
        }
        return res;
    }
};