#include <vector>

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int res = -1, all_sum = 0, min_sum = INT_MAX;
        for (int i = 0; i < gas.size(); ++i)
        {
            all_sum += gas[i] - cost[i];
            if (min_sum > all_sum) 
            {
                min_sum = all_sum;
                res = (i + 1)%gas.size();
            }
        }
        if (all_sum < 0) return -1;
        return res;
    }
};