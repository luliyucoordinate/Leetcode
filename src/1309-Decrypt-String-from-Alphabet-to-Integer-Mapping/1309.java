class Solution {
    public String freqAlphabets(String s) {
        String res = "";
        for (int i = 0; i < s.length(); i++) {
            if (i + 2 < s.length() && s.charAt(i + 2) == '#') {
                res += (char)(Integer.parseInt(s.substring(i, i + 2)) + 96);
                i += 2;
            } else res += (char)(s.charAt(i) - '1' + 97);
        }
        return res;
    }
}