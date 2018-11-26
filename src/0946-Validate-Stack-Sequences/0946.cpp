#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        vector<int> tmp;
        while (!pushed.empty())
        {
            auto p = pushed.begin();
            tmp.push_back(*p);
            pushed.erase(p);
            
            auto q = popped.begin();
            while (!tmp.empty() and *q == *(tmp.rbegin()))
            {
                popped.erase(q);
                tmp.pop_back();
            }
        }
        return tmp.empty();
    }
};