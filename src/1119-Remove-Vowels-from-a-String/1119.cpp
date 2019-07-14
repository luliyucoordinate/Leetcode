class Solution 
{
public:
    string removeVowels(string S) 
    {
        return regex_replace(S, regex("a|e|i|o|u"), "");
    }
};