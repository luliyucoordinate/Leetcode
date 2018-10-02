#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using  namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int result = 0;

        make_heap(g.begin(), g.end());
        sort_heap(g.begin(), g.end());
        make_heap(s.begin(), s.end());
        sort_heap(s.begin(), s.end());
        
        for (auto g_st = g.begin(), s_st = s.begin(); g_st != g.end() 
                                    and s_st != s.end(); ++s_st)
        {
            result += (*s_st >= *g_st);
            g_st += (*s_st >= *g_st);
        }
        return result;
    }
};
int main()
{
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    cout << Solution().findContentChildren(g, s) << endl;
    return 0;
}
