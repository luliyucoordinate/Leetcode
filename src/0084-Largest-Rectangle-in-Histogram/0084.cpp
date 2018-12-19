#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        vector<int> stack;
        int res = 0;
        heights.push_back(-1);
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!stack.empty() and heights[*(stack.rbegin())] >= heights[i])
            {
                int height_id = *(stack.rbegin()); stack.pop_back();
                int pre_id = stack.empty() ? -1 : *(stack.rbegin());
                res = max(res, heights[height_id]*(i - pre_id - 1));
            }
            stack.push_back(i);
        }
        return res;
    }
};