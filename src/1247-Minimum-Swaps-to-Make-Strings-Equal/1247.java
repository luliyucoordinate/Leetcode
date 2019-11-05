class Solution {
    public int minimumSwap(String s1, String s2) {
        int x = 0, y = 0, n = s1.length();
        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                if (s1.charAt(i) != 'x') x++;
                else y++;
            }
        }
        if ((x + y) % 2 == 1) return -1;
        return x / 2 + y / 2 + 2 * (x % 2);
    } 
}