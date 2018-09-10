#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int l = 0;
        int r = height.size() - 1;
        int contain = 0;
        while (l < r)
        {
            contain = max(contain, (r - l)* min(height[l], height[r]));
            if (height[l] > height[r]) --r;
            else ++l;
        }
        return contain;
    }
};
int main()
{
    vector<int> height = {1, 1};
    cout << Solution().maxArea(height) << endl;
    return 0;
}