class Solution {
    public String toGoatLatin(String S) {
        Set vowels = new HashSet();
        for (char c : "aeiouAEIOU".toCharArray()) vowels.add(c);
        String res = "";
        String[] tokens = S.split(" ");
        int i = 0;
        for (String w : tokens) {
            res += ' ' + (vowels.contains(w.charAt(0)) ? w : w.substring(1) + w.charAt(0)) + "ma";
            res += String.join("", Collections.nCopies(++i, "a"));
        };
        return res.substring(1);
    }
}