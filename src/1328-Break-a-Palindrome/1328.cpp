class Solution 
{
public:
    string breakPalindrome(string p) 
    {
        for (int i = 0; i < p.size()/2; i++)
        {
            if (p[i] != 'a') 
            {
                p[i] = 'a';
                return p;
            }
        }
        p[p.size() - 1] = 'b';
        return p.size() > 1 ? p : "";
    }
};