class Solution {
    public int numTimesAllBlue(int[] light) {
        int res = 0, maxv = 0;
        for (int i = 0; i < light.length; i++) {
            maxv = Math.max(maxv, light[i]);
            if (maxv == i + 1) res++;
        }
        return res;
    }
}