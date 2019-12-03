class Solution {
    public String toHexspeak(String num) {
        StringBuilder res = new StringBuilder();
        char[] data = Long.toHexString(Long.parseLong(num)).toUpperCase().toCharArray();
        for (char i : data) {
            if (i > '1' && i <= '9') return "ERROR";
            if (i == '0') res.append('O');
            else if (i == '1') res.append('I');
            else res.append(i);
        }
        return res.toString();
    }
}