#pragma once
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    bool _isEqual(char l, char r)
    {
        if ('A' <= l && l <= 'Z') l += 32;
        if ('A' <= r && r <= 'Z') r += 32;
        return l == r;
    }
    bool isPalindrome(string s) 
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            if (!(bool)isalnum(s[l]))
            {
                ++l;
                continue;
            }
            if (!(bool)isalnum(s[r]))
            {
                --r;
                continue;
            }
            if (!_isEqual(s[l], s[r])) return false;
            else
            {
                ++l; --r;
            }
        }
        return true;
    }
};
int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << Solution().isPalindrome(s) << endl;
    return 0;
}