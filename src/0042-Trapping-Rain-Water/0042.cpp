#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r) 
        {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};