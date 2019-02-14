static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int brokenCalc(int X, int Y) 
    {
        if (X >= Y) return X - Y;
        return 1 + brokenCalc(X, Y % 2 ? Y + 1: Y / 2);
    }
};