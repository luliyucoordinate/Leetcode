#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        nth_element(points.begin(), points.begin() + K, points.end(), [](vector<int> &a, vector<int> &b) {
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        });
        points.resize(K);
        return points;
    }
};