class Solution {
public:
    string longestDiverseString(int A, int B, int C, char a='a', char b='b', char c='c') {
        if (A < B) return longestDiverseString(B, A, C, b, a, c);
        if (B < C) return longestDiverseString(A, C, B, a, c, b);
        if (B == 0) return string(min(2, A), a);
        int na = min(2, A), nb = A - na + 1 >= B ? 1 : 0;
        return string(na, a) + string(nb, b) + longestDiverseString(A - na, B - nb, C, a, b, c);
    }
};