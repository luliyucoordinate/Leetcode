#include <vector>
#include <iostream>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int countTriplets(vector<int>& A) 
    {
        int arr[1<<16] = {};
        int all = (1<<16) - 1;
        for(int a : A)
        {
            int k = all ^ a;
            for(int i=k; ; i = (i-1) & k)
            {
                arr[i ^ a]++;
                if(i == 0) break;
            }
        }
        
        int res = 0;
        for (int a : A)
        {
            for (int b : A)
            {
                res += arr[all ^ (a&b)];
            }
        }
        return res;
    }
};