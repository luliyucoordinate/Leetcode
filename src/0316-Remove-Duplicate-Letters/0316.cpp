class Solution 
{
public:
    string removeDuplicateLetters(string s) 
    {
        int cnt[26];
        memset(cnt, 0, sizeof cnt);
        bool visited[26];
        memset(visited, 0, sizeof visited);
        for (char ch : s) cnt[ch - 'a']++;

        
        string res;
        for (char ch : s) 
        {
            cnt[ch - 'a']--;
            if (visited[ch - 'a']) continue;
            while (res.size() and res.back() > ch and cnt[res.back() - 'a'] > 0) 
            {
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(ch);
            visited[ch - 'a'] = true;
        }
        return res;
    }
};