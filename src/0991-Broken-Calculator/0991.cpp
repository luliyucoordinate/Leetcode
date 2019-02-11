static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int brokenCalc(int X, int Y) 
    {
        int res = 0;
        while (X < Y)
        {
            res += (Y % 2) + 1;
            Y = (Y + 1) / 2;
        }
        return res + X - Y;
    }
};