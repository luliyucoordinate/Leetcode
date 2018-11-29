#include <vector>
#include <cctype>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> diffWaysToCompute(string input) 
    {
        vector<int> res;
        for (int i = 0; i < input.size(); i++) 
        {
            char c = input[i];
            if (ispunct(c))
            {
                for (int a : diffWaysToCompute(input.substr(0, i)))
                {
                    for (int b : diffWaysToCompute(input.substr(i+1)))
                    {
                        res.push_back(c == '+' ? a+b : c == '-' ? a-b : a*b);
                    }    
                }     
            }
        }
        return res.size() ? res : vector<int>{stoi(input)};
    };
};