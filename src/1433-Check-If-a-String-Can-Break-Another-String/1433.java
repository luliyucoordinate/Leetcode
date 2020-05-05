class Solution {
    public boolean checkIfCanBreak(String s1, String s2) {
        int[] d1 = new int[26];
        int[] d2 = new int[26];
        for (char c : s1.toCharArray()) d1[c - 'a']++;
        for (char c : s2.toCharArray()) d2[c - 'a']++;
        
        return check(d1, d2) || check(d2, d1);
    }

    private boolean check(int[] d1, int[] d2) {
        int s = 0;
        for (int i = 0; i < 26; i++) {
            s += d1[i] - d2[i];
            if (s < 0) return false;
        }
        return true;
    }
}