#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Definition for an interval.
struct Interval 
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) 
    {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2){
            if (i1.start != i2.start) return i1.start < i2.start;
            return i1.end < i2.end;
        });
        int result = 0;
        auto prev = intervals.begin();
        for (auto cur = intervals.begin() + 1; cur != intervals.end(); ++cur)
        {
            if (prev->end > cur->start)
            {
                ++result;
                if (cur->end < prev->end) prev = cur;
            }
            else prev = cur;
        }
        return result;
    }
};