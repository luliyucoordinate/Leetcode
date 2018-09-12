#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<string> readBinaryWatch(int num) 
    {
        vector<string> result;
        for (unsigned int h = 0; h < 12; ++h)
        {
            for (unsigned int m = 0; m < 60; ++m)
            {
                if ((countOnes(h) + countOnes(m)) == num)
                {
                    stringstream ss;
                    ss << h << ":" << setfill('0') << setw(2) << m;
                    result.push_back(ss.str());
                }
            }
        }
        return result;
    }
private:
    unsigned int countOnes(int num)
    {
        unsigned int count = 0;
        while (num != 0)
        {
            num = num & (num - 1);
            count++;
        }
        return count;
    }
};