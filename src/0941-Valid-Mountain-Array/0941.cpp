#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool validMountainArray( vector<int>& A )
    {
        return 1 == distance(
            adjacent_find(A.cbegin(), A.cend(), greater_equal<int>()),
            adjacent_find(A.crbegin(), A.crend(), greater_equal<int>()).base());
    }
};

int main()
{
    vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}};
    cout << Solution().minAreaRect(points);
    return 0;
}
