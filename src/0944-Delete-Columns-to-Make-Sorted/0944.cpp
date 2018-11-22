#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minDeletionSize(vector<string>& A) 
    {
        if (A.empty()) return 0;
        int result = 0;
        for (auto c = 0; c < A[0].size(); ++c)
        {
            for (auto i = 0; i < A.size()-1; ++i) 
            {
                if (A[i][c] > A[i+1][c]) 
                {
                    ++result; break;
                }
            }
        }
        return result;
    }
};

int main()
{
    string S = "IDID";
    cout << Solution().diStringMatch(S);
    return 0;
}
