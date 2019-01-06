#include <vector>
#include <unordered_set>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound) 
    {
        unordered_set<int> set;
        int i = x == 1 ? bound : x;
        int j = y == 1 ? bound : y;
        
        for (int m = 1; m < bound; m *= i)
        {
            for (int n = 1; m + n <= bound; n *= j) set.insert(m + n);
        }
        
        return vector<int>(begin(set), end(set));
    }
};