class Solution {
    public int numSteps(String s) {
        int res = 0, add = 0, n = s.length();
        
        for (int i = n - 1; i > 0; i--) {
            res++;
            if (s.charAt(i) - '0' + add == 1) {
                add = 1;
                res++;
            }
        }
        return res + add;
    }
}