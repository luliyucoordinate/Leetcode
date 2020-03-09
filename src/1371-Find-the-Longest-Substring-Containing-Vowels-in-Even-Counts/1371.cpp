class Solution 
{
public:
    int findTheLongestSubstring(string s) 
    {
        int vowels[26] = {};
        vowels['a' - 'a'] = 1;
        vowels['e' - 'a'] = 2;
        vowels['i' - 'a'] = 4;
        vowels['o' - 'a'] = 8;
        vowels['u' - 'a'] = 16;
        
        int vis[32] = {};
        vis[0] = 1;
        int res = 0, cur = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cur ^= vowels[s[i] - 'a'];
            if (vis[cur] == 0) vis[cur] = i + 2;
            res = max(res, i - vis[cur] + 2);
        }
        return res;
    }
};