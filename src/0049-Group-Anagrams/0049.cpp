#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string> > group;
        for (const auto &s : strs) 
        {
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
        
        vector<vector<string>> anagrams;
        for (const auto m : group) 
        { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (auto& i : Solution().groupAnagrams(strs))
    {
        for (auto& j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}