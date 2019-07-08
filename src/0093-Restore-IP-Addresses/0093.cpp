#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> result;
        if (!s.empty() and s.size() < 4 or s.size() > 12) return result;
        _restoreIpAddresses(s, 4, 0, string(""), result);
        return result;
    }

private:
    void _restoreIpAddresses(string s, int n, int index, string ip, vector<string>& result)
    {
        if (n == 0) 
        {
            if (index == s.size()) result.push_back(ip);
            return;
        }

        for (int i = index + 1; i <= s.size(); ++i)
        {
            string tmpS = string(s.begin() + index, s.begin() + i);
            if (isNum(tmpS))
            {
                if (ip.empty())
                    _restoreIpAddresses(s, n - 1, i, tmpS, result);
                else
                {
                    tmpS = ip+"."+tmpS;
                    _restoreIpAddresses(s, n - 1, i, tmpS, result);
                }                 
            }
            else break;            
        }
    }

    bool isNum(string num)
    {
        if (0 <= stoi(num) and stoi(num) <= 255 and to_string(stoi(num)) == num)
        {
            return true;
        }
        return false;
    }
};