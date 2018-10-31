#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> threeEqualParts(vector<int>& A) 
    {
        int ones = 0;
        for(auto c: A)
        {
            if(c == 1) ones++;
        } 								
        if(ones == 0) return {0, A.size()-1};
        if(ones % 3 != 0) return {-1, -1};
						
        int step1 = ones/3+1, step2 = ones*2/3+1;
        int p1 = 0, p2 = 0, p3 = 0;
        for(unsigned int i = 0; i < A.size(); i++)
        {
            if (A[i] == 1) 
            {
                p1 = i;
                break;
            }
        }
        for(unsigned int i = 0; i < A.size(); i++)
        {
            if (A[i] == 1) step1--;
            if (0 == step1) 
            {
                p2 = i;
                break;
            }
        }
        for(unsigned int i = 0; i < A.size(); i++)
        {
            if (A[i] == 1) step2--;
            if (0 == step2) 
            {
                p3 = i;
                break;
            }
        }
        while(p3 < A.size() and A[p1] == A[p2] and A[p2] == A[p3])
        {
            p1++; p2++; p3++;
        }
        
        if (p3 == A.size()) return {p1-1, p2};
        return {-1, -1};
    }
};
int main()
{
    vector<int> A = {1,1,1};
    auto result = Solution().threeEqualParts(A);
    return 0;
}