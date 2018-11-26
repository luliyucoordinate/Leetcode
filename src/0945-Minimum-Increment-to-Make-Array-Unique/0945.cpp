#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minIncrementForUnique(vector<int>& A) 
    {
        int box[40000]{};
        int result = 0, max_A = 0;
        for (auto a : A)
        {
            box[a]++;
            if (max_A < a) max_A = a;
        }
        for (int i = 0; i < max_A; ++i)
        {
            if (box[i] <= 1) continue;
            int ano = box[i] - 1;
            result += ano;
            box[i+1] += ano;
            box[i] = 1;
        }
        int last_ano = box[max_A] - 1;
        result += (1 + last_ano)*last_ano/2;
        return result;
    }
};