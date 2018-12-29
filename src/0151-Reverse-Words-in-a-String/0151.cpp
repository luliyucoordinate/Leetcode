static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    void reverseWords(string &s) 
    {
        if (s.size() == 0) return;
        
        istringstream words(s);
        string result = "", word;

        while (words >> word) result.insert(0, word + ' ');
        if (result.size() > 0) result.pop_back();
        s = result;
    }
};