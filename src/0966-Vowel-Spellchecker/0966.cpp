#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) 
    {
        unordered_map<string, string> words;
        for (auto w : wordlist) 
        {
            words.insert({ w, w }), words.insert({ lowerKey(w), w }), words.insert({ vowelKey(w), w });
        }
        vector<string> res;
        for (auto q : queries) 
        {
            auto it = words.find(q);
            if (it == words.end()) it = words.find(lowerKey(q));
            if (it == words.end()) it = words.find(vowelKey(q));
            if (it != words.end()) res.push_back(it->second);
            else res.push_back("");
        }
        return res;
    }

private:
    string lowerKey(string &s) 
    {
        return accumulate(begin(s), end(s), string("_"), [](string k, char c) { return k + (char)tolower(c); });
    }
    string vowelKey(string &s) 
    {
        return accumulate(begin(s), end(s), string(""), [](string k, char c) { return k +
            (char)(string("aeiou").find(tolower(c)) != string::npos ? '*' : tolower(c)); });
    }
};