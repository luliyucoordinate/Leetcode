#include <string>
#include <algorithm>

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class WordDictionary 
{
public:
    /** Initialize your data structure here. */
    WordDictionary() 
    {
        data.clear();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
        data[word.length()].insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(const string& word) 
    {
        auto it = data.find(word.size());
        
        if(it == data.end()) return false;
        if(it->second.count(word)) return true;
        
        auto match = [&](const string& s)
        {
            for(int i = 0; i < word.size(); ++i)
            {
                if(word[i] != '.' && s[i] != word[i])
                {
                    return false;
                }
            }
            return true;
        };
        
        return find_if(it->second.begin(), it->second.end(), match) != it->second.end();
    }

private:
    unordered_map<int, unordered_set<string>> data;
};