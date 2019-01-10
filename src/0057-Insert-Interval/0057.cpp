#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
    {
        vector<Interval> res;
        int i = 0;
        while (i < intervals.size() and intervals[i].end < newInterval.start)
        {
            res.push_back(intervals[i++]);
        }
        
        while (i < intervals.size() and intervals[i].start <= newInterval.end)
        {
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            ++i;
        }
        res.push_back(newInterval);
        for (; i < intervals.size(); ++i) res.push_back(intervals[i]);
        return res;
    }
};