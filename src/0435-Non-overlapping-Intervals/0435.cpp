#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        }); 
        
        int res = 0;
        auto pre = intervals.begin();
        for (auto cur = intervals.begin() + 1; cur != intervals.end(); cur++)
        {
            if ((*pre)[1] > (*cur)[0])
            {
                ++res;
                if ((*cur)[1] < (*pre)[1]) pre = cur;
            }
            else pre = cur;
        }
        return res;
    }
};