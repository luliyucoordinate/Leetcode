static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    string reverseWords(string s) 
    {
        istringstream words(s);
        string res, word;

        while (words >> word) res.insert(0, word + ' ');
        if (res.size() > 0) res.pop_back();
        return res;
    }
};