#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> sortArrayByParityII(vector<int>& A) 
    {
        int i = 0, j = 1;
        vector<int> result(A.size(), 0);
        for (auto& a : A)
        {
            if ((a&1) == 0) 
            {
                result[i] = a; i += 2;
            }
            else
            {
                result[j] = a; j += 2;
            }
        }
        return result;
    }
};
int main()
{
    vector<int> A = {4,2,5,7};
    auto result = Solution().sortArrayByParityII(A);
    for (auto& val: result)
        cout << val << " ";
    return 0;
}