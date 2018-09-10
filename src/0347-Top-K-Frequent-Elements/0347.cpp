#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> countMap;
        vector<int> result;
        for (auto& i : nums)
        {
            ++countMap[i];
        }
        for (auto& i : countMap)
        {
            result.push_back(i.first);
        }
        sort(result.begin(), result.end(), [&countMap](int a, int b){ return countMap[a] > countMap[b];});
        return vector<int>(result.begin(), result.end() + k);
    }
};
int main()
{
    vector<int> nums = {4,1,1,1,2,2,3};
    int k = 2;
    for (auto& i : Solution().topKFrequent(nums, k))
        cout << i << endl;
    return 0;
}