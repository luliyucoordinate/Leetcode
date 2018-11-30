#include <deque>
#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        if (s1.size() + s2.size() != s3.size()) return false;
        deque<deque<bool>> mem(s1.size() + 1, deque<bool>(s2.size() + 1, false));
        for (int i = 0; i <= s1.size(); ++i)
        {
            for (int j = 0; j <= s2.size(); ++j)
            {
                if (i == 0 and j == 0) mem[i][j] = true;
                else if (i == 0) mem[i][j] = mem[i][j - 1] and (s2[j - 1] == s3[i + j - 1]);
                else if (j == 0) mem[i][j] = mem[i - 1][j] and (s1[i - 1] == s3[i + j - 1]);
                else mem[i][j] = (mem[i][j - 1] and (s2[j - 1] == s3[i + j - 1])) or (
                                  mem[i - 1][j] and (s1[i - 1] == s3[i + j - 1]));
            }
        }
        return mem[s1.size()][s2.size()];
    }
};