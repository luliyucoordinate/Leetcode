static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        long long x = min(C, G) + 0ll - max(A, E);
        long long y = min(D, H) + 0ll - max(B, F);
        return (C - A) * (D - B) + 0ll + (G - E) * (H - F) - max(x, 0ll)*max(y, 0ll);
    }
};