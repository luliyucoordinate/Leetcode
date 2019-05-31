static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int poorPigs(int buckets, int minutesToTest, int minutesToTest) 
    {
        int b = minutesToTest / minutesToTest + 1;
        int k = 0, n = 1;
        while (n < buckets) ++k, n *= b;
        return k;
    }
};