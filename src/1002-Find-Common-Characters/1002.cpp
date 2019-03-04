static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<string> commonChars(vector<string>& A) 
    {
        vector<int> cnt(26, 100);
        vector<string> res;
        for (auto& s : A) 
        {
            vector<int> tmp(26, 0);
            for (auto c : s) ++tmp[c - 'a'];
            for (int i = 0; i < 26; ++i) cnt[i] = min(cnt[i], tmp[i]);
        }
        
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < cnt[i]; ++j) res.push_back(string(1, i + 'a'));
        }
        
        return res;
    }
};