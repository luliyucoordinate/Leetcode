#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> diStringMatch(string S) 
    {
        vector<int> result;
        int l = 0, r = S.size();
        for (auto ch : S) 
        {
            if (ch == 'I') result.push_back(l++);
            else result.push_back(r--);
        }
        result.push_back(r);
        return result;
    }
};

int main()
{
    string S = "IDID";
    cout << Solution().diStringMatch(S);
    return 0;
}
