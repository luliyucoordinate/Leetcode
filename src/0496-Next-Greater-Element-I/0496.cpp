#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
    {
        unordered_map<int, int> dic;
        vector<int> stack;
        for (int n : nums)
        {
            while (!stack.empty() and stack.back() < n)
            {
                dic[stack.back()] = n; stack.pop_back();
            }
            stack.push_back(n);
        }
        vector<int> res;
        for (int n : findNums)
        {
            if (dic.count(n)) res.push_back(dic[n]);
            else res.push_back(-1);
        }
        return res;
    }
};