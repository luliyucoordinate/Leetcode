#include <string>
#include <unordered_map>

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        if (words.empty()) return {};
        unordered_map<string, int> words_dict;
        for (auto& word : words) words_dict[word]++;
        vector<int> res;
        int word_len = words[0].size();
        for (int k = 0; k < word_len; ++k)
        {
            unordered_map<string, int> has_words;
            int num = 0;
            for (int i = k; i < s.size(); i += word_len)
            {
                string word = s.substr(i, word_len);
                if (words_dict.count(word) != 0)
                {
                    ++num; ++has_words[word];
                    while (has_words[word] > words_dict[word])
                    {
                        int pos = i - word_len*(num - 1);
                        string rem_word = s.substr(pos, word_len);
                        has_words[rem_word]--; num--;
                    }
                }
                else
                {
                    has_words.clear(); num = 0;
                }
                if (num == words.size()) res.push_back(i - word_len*(num - 1));
            }
        }
        return res;
    }
};