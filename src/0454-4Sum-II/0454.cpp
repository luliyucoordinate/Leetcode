#include <iostream>
#include <vector>
#include <unordered_map>
using  namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        unordered_map<int, int> record;
        for (auto& i : C)
        {
            for (auto& j : D)
            {
                ++record[i + j];
            }
        }
        int result = 0;
        for (auto& i : A)
        {
            for (auto& j : B)
            {
                if (record.count(- i - j))
                {
                    result += record[- i - j];
                }
            }
        }
        return result;
    }
};
int main()
{
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    cout << Solution().fourSumCount(A, B, C, D) << endl;
    return 0;
}
