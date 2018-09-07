#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char, int> str_map1;
        unordered_map<char, int> str_map2;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); ++i)
        {
            if (str_map1[s[i]] != str_map2[t[i]])
            {
                return false;
            }
            str_map1[s[i]] = str_map2[t[i]] = i + 1;
        }
        return true;
    }
};
int main()
{
    string pattern = "egg";
    string str = "add";
    cout << Solution().isIsomorphic(pattern, str) << endl;
    return 0;
}