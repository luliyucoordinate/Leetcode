#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2){
            return i1.start < i2.start;
        });
        vector<Interval> result;
        for (auto& item : intervals)
        {
            if (result.empty() or (result.rbegin())->end < item.start)
                result.push_back(item);
            else
            {
                if ((result.rbegin())->end < item.end)
                    (result.rbegin())->end = item.end;
            }
        }
        return result;
    }
};
int main()
{
    vector<Interval> nums = {Interval(1,3), Interval(2,6)};
    auto result =  Solution().merge(nums);
}