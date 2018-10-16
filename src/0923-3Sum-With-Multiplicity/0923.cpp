#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int threeSumMulti(vector<int>& A, int target) 
    {
        unordered_map<int, long> mem;
        for (auto& a : A) mem[a]++;
        long result = 0;
        for (auto& it : mem)
        {
            for (auto& it2 : mem) 
            {
                int i = it.first, j = it2.first, k = target - i - j;
                if (!mem.count(k)) continue;
                if (i == j && j == k)
                    result += mem[i] * (mem[i] - 1) * (mem[i] - 2) / 6;
                else if (i == j && j != k)
                    result += mem[i] * (mem[i] - 1) / 2 * mem[k];
                else if (i < j && j < k)
                    result += mem[i] * mem[j] * mem[k];
            }
        }
        return result % (int)(1e9 + 7);
    }
};
int main()
{
    vector<int> A = {1,2,3,3,1};
    int target = 5;
    cout << Solution().threeSumMulti(A, target);
    return 0;
}