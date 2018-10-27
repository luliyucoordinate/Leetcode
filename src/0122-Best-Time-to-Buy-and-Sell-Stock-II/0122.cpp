#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {  
        int result = 0;
        if (prices.empty()) return result;
        for (unsigned int i = 0; i < prices.size() - 1; ++i)
        {
            if (prices[i] < prices[i+1]) 
                result += prices[i+1] - prices[i];
        }
        return result;
    }
};
int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().maxProfit(prices);
}