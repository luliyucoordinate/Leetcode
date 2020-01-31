class Solution {
    public String breakPalindrome(String palindrome) {
        char[] p = palindrome.toCharArray();
        for (int i = 0; i < p.length/2; i++) {
            if (p[i] != 'a') {
                p[i] = 'a';
                return String.valueOf(p);
            }
        }
        p[p.length - 1] = 'b';
        return p.length > 1 ? String.valueOf(p) : "";
    }
}