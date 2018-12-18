#include <algorithm>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:  
    int tallestBillboard(vector<int>& rods) 
    {
        if(rods.size() == 0 || rods.size() == 1) return 0;
        sort(rods.begin(), rods.end(), greater<int>());
        int maxsum = 0;
        
        for(int rod : rods)
            maxsum += rod;
        
        dfs(rods, maxsum-rods[0], 0, rods[0], 0);
        dfs(rods, maxsum-rods[0], 0, 0, 0);
        
        return maxheight;
    }
private:
    int maxheight;
    
    
    void dfs(vector<int> &rods, int remain, int i, int left, int right)
    {
        if((abs(left-right) > remain)
          || (left + right + remain <= maxheight * 2))
            return;
        
        if(left == right)
            maxheight = max(maxheight, left);
        
        i++;
        if (i == rods.size()) return;
        
        remain -= rods[i];
        dfs(rods, remain, i, left+rods[i], right);
        dfs(rods, remain, i, left, right+rods[i]);
        dfs(rods, remain, i, left, right);
    }
};