#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> beautifulArray(int N) 
    {
        vector<int> result = {1};
        while (result.size() < N)
        {
            vector<int> tmp;
            for (auto i : result)
            {
                if (i*2 - 1 <= N) tmp.push_back(i*2 - 1);
            }
            for (auto i : result)
            {
                if (i*2 <= N) tmp.push_back(i*2);
            }
            result = tmp;
        }
        return result;
    }
};
int main()
{
    int N = 4;
    auto result = Solution().beautifulArray(N);
    return 0;
}
