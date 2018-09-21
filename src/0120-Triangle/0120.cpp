#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        if (triangle.empty()) return 0;
        for (unsigned int i = triangle.size() - 1; i > 0; --i)
        {
            for (unsigned int j = 0; j < triangle[i - 1].size(); ++j)
            {
                triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
int main()
{
}