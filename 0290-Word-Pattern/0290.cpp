#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    bool wordPattern(string pattern, string str) 
    {
        unordered_map<char, int> str_map1;
        unordered_map<string, int> str_map2;
        istringstream in(str);
        int i = 0;
        for (string word; in >> word; ++i)
        {
            if (i == pattern.size() || str_map1[pattern[i]] != str_map2[word])
            {
                return false;
            }
            str_map1[pattern[i]] = str_map2[word] = i + 1;
        }
        return i == pattern.size();
    }
};
int main()
{
    string pattern = "abba";
    string str = "dog cat cat fish";
    cout << Solution().wordPattern(pattern, str) << endl;
    return 0;
}