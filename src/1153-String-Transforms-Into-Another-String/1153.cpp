class Solution 
{
public:
    bool canConvert(string str1, string str2) 
    {
        unordered_set<char> s2(str2.begin(), str2.end());
        if (s2.size() == 26) return str1 == str2;
        
        unordered_map<char, char> d;
        for (int i = 0; i < str1.size(); ++i)
        {
            if (d.count(str1[i])) 
            {
                if (d[str1[i]] != str2[i]) return false;
            }
            else d[str1[i]] = str2[i];
        }   
        return true;
    }
};