class Solution {
    public boolean checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int x = (x1 + x2) / 2, y = (y1 + y2) / 2;
        int[] h = {x2 - x, y2 - y};
        int[] v = {Math.abs(x - xc), Math.abs(y - yc)};
        int[] u = {Math.max(v[0] - h[0], 0), Math.max(v[1] - h[1], 0)};
        return r * r >= u[0] * u[0] + u[1] * u[1]; 
    }
}