class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int x = (x1 + x2) / 2, y = (y1 + y2) / 2;
        vector<int> h = {x2 - x, y2 - y};
        vector<int> v = {abs(x - xc), abs(y - yc)};
        vector<int> u = {max(v[0] - h[0], 0), max(v[1] - h[1], 0)};
        return r * r >= u[0] * u[0] + u[1] * u[1]; 
    }
};