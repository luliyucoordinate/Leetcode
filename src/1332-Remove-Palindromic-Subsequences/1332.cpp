class Solution 
{
public:
    int removePalindromeSub(string s) 
    {
        return 2 - (s == string(s.rbegin(), s.rend())) - s.empty();
    }
};