#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    struct Ch 
    {
        int key;
        int val;
        Ch(int key, int val):key(key), val(val){}
        bool operator < (const Ch& other) const {
            return val < other.val;
        }
    };
    string frequencySort(string s) 
    {
        unordered_map<char, int> str_map;
        for (auto& i : s)
        {
            ++str_map[i];
        }
        priority_queue<Ch> qChar;
        for (int i = 0; i < 255; i++) 
        {
            if (str_map[i]) 
            {
                Ch c(i, int(str_map[i]));
                qChar.push(c);
            }
        }
        string result;
        while (!qChar.empty())
        {
            int key = qChar.top().key;
            int val = qChar.top().val;
            while (val--) 
            {
                result.push_back((char)key);
            }
            qChar.pop();
        }
        return result;
    }
};
int main()
{
    string s = "cccaaa";
    cout << Solution().frequencySort(s) << endl;
    return 0;
}