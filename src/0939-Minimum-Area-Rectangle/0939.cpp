#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minAreaRect(vector<vector<int>>& points) 
    {
        int result = INT_MAX;
        unordered_map<int, set<int>> columns;
        for (auto point : points) columns[point[0]].insert(point[1]);
        for (auto x1 = columns.begin(); x1 != columns.end(); ++x1) 
        {
            if (x1->second.size() < 2) continue;
            for (auto x2 = next(x1); x2 != columns.end(); ++x2) 
            {
                if (x2->second.size() < 2) continue;
                vector<int> y;
                set_intersection(begin(x1->second), end(x1->second),
                    begin(x2->second), end(x2->second), inserter(y, y.begin()));
                for (unsigned int i = 1; i < y.size(); ++i)
                    result = min(result, abs(x2->first - x1->first) * (y[i] - y[i - 1]));
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};


int main()
{
    vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}};
    cout << Solution().minAreaRect(points);
    return 0;
}
