#include <string>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        int haystack_size = haystack.size(), needle_size = needle.size();
        if (haystack_size < needle_size) return -1;
        if (haystack_size == needle_size) return haystack == needle ? 0 : -1;
        for (int i = 0; i <= haystack_size - needle_size; ++i)
        {
            if (haystack.substr(i, needle_size) == needle) return i;
        }
        return -1;
    }
};