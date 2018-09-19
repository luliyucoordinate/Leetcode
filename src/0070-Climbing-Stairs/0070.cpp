#include <iostream>
#include <unordered_map> 
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int climbStairs(int n) 
    {
        if (n == 0 or n == 1) return 1;
        if (climb.count(n) == 0) climb[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return climb[n];
    }
private:
    unordered_map<int, int> climb;
};

int main()
{
    int n = 4;
    cout << Solution().climbStairs(4);
}