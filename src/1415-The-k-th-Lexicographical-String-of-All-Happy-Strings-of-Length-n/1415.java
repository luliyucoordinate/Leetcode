class Solution {
    public String getHappyString(int n, int k) {
        int prem = 1 << (n - 1);
        if (k > 3 * prem) return "";
        
        k--;
        StringBuilder s = new StringBuilder();
        s.append((char)(97 + k / prem));
        while (prem > 1) {
            k %= prem;
            prem >>= 1;
            s.append(k / prem == 0 ? s.charAt(s.length() - 1) == 'a' ? 'b' : 'a' :
                                    s.charAt(s.length() - 1) != 'c' ? 'c' : 'b');
        }
        return s.toString();
    }
}