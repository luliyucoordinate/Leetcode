static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isScramble(string s1, string s2) 
    {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        
        string s_1 = s1, s_2 = s2;
        sort(s_1.begin(), s_1.end());
        sort(s_2.begin(), s_2.end());
        if (s_1 != s_2) return false;

        for (int i = 1; i < s1.size(); ++i)
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) and 
                isScramble(s1.substr(i, s1.size()-i), s2.substr(i, s1.size()-i)))
                return true;

            if (isScramble(s1.substr(0, i), s2.substr(s1.size()-i, i)) and 
                isScramble(s1.substr(i, s1.size()-i), s2.substr(0, s1.size()-i)))
                return true;  
        }
        return false;
    }
};