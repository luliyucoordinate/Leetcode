class Solution 
{
public:
    string sortString(string s) 
    {
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;
        
        string res;
        while(res.size() < s.size()) 
        {
            for (int i = 0; i < 26; ++i) 
            {
                if (cnt[i]) 
                {
                    res += ('a' + i);
                    --cnt[i];
                }
            }
            
            for (int i = 25; i >= 0; --i)
            {
                if (cnt[i]) 
                {
                    res += ('a' + i);
                    --cnt[i];
                }
            }
        }
        return res;
    }
};