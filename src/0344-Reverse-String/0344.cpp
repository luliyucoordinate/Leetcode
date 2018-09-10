#include <string>
#include <iostream>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution {
public:
    string reverseString(string s) 
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
int main()
{
    string s = "hello";
    cout << Solution().reverseString(s) << endl;
    return 0;
}