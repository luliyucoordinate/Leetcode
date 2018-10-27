#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int result = 0;
        int buy = INT_MAX;
        for (auto price : prices)
        {
            if (buy > price) buy = price;
            if (result < price - buy) result = price - buy;
        }
        return result;

    }
};
int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().maxProfit(prices);
}