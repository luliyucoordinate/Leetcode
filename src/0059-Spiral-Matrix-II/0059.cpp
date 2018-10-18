#include <iostream>
#include <vector>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int start = 0, end = n-1;
        vector<vector<int>> result(n, vector<int>(n, 0));
        int fill = 1;
        while (start <= end)
        {
            for(int i = start; i <= end; i++)
                result[start][i] = fill++;
            
            for(int i = start+1; i <= end-1; i++)
                result[i][end] = fill++;
            
            if(start != end)
                for(int i = end; i >= start; i--)
                    result[end][i] = fill++;

            if(start != end)
                for(int i = end-1; i >= start+1; i--)
                    result[i][start] = fill++;

            start++; end--;
        }
        return result;
    }
};
int main()
{
    int n = 3;
    auto result = Solution().generateMatrix(n);
}