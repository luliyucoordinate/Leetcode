#include <vector>
#include <string>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        helper(res, "", n, 0);
        return res;
    }
private:
    void helper(vector<string> &res, string str, int n, int m)
    {
        if (n == 0 and m == 0) 
        {
            res.push_back(str);
            return;
        }
        if (m > 0) helper(res, str + ")", n, m - 1); 
        if (n > 0) helper(res, str + "(", n - 1, m + 1); 
    }
};