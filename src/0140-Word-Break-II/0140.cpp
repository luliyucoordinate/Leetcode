#include <vector>
#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string> out = _wordBreak(0, s, wordDict);
        for (int i = 0; i < out.size(); ++i) out[i].pop_back();
        return out;
    }

private:
    unordered_map<int, vector<string> > mem;
    
    vector<string> _wordBreak(int st, string& s, vector<string>& wordDict) 
    {
        if (mem.count(st)) return mem[st];

        for (int i = 0; i < wordDict.size(); ++i) 
        {
            if (s.substr(st, wordDict[i].length()) == wordDict[i]) 
            {
                vector<string> sublist = _wordBreak(st + wordDict[i].length(), s, wordDict);
                for(auto& it : sublist)
                  mem[st].push_back(wordDict[i] + " " +it);
            }
        }
        if (!mem.count(st) && st == s.length()) mem[st].push_back("");
        return mem[st];
    }
};