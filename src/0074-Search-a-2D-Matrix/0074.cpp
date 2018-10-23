#include <iostream>
#include <vector>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.empty()) return false;
        int r = matrix.size(), c = matrix[0].size();
        int left = 0, right = r*c;
        while (left < right)
        {
            int mid = (right - left)/2 + left;
            int m = mid/c, n = mid%c;
            if (matrix[m][n] == target) return true;
            else if (matrix[m][n] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};
int main()
{
    vector<vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
    int target = 13;
    cout << Solution().searchMatrix(matrix, target);
    return 0;
}