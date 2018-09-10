#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:    
    int numberOfBoomerangs(vector<pair<int, int>>& points) 
    {
        int result = 0;
        for (auto& i : points)
        {
            unordered_map<int, int> record;
            for (auto& j : points)
            {
                if (j != i)
                {
                    ++record[dis(i, j)];
                }
            }
            for (auto& val : record)
            {
                if (val.second >= 2)
                {
                    result += val.second*(val.second - 1);
                }
            }
        }
        return result;
    }
private:
    static inline int dis(pair<int, int>& point1, pair<int, int>& point2)
    {
        return pow((point1.first - point2.first), 2) + pow((point1.second - point2.second), 2);
    }
};
int main()
{
    vector<pair<int, int>> points = {make_pair(0,0),make_pair(1,0),make_pair(2,0)};
    cout << Solution().numberOfBoomerangs(points);
    return 0;
}