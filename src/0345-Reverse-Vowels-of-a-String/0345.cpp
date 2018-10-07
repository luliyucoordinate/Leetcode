#include <string>
#include <iostream>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution
{
public:
    string reverseVowels(string s) 
    {
        string vowels = "aeiouAEIOU";
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            l = s.find_first_of(vowels, l);
            r = s.find_last_of(vowels, r);
            if (l < r)
            {
                char tmp = s[l];
                s[l++] = s[r];
                s[r--] = tmp;
            }
        }
        return s;
    }
};
int main()
{
    string s = "hello";
    cout << Solution().reverseVowels(s) << endl;
    return 0;
}