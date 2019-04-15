static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool divisorGame(int N) 
    {
        return (N & 1) == 0;
    }
};