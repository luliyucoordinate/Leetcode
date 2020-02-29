class Solution {
    public String largestMultipleOfThree(int[] digits) {
        int[] cnt = new int[10];
        for (int d : digits) cnt[d]++;
        int b1 = cnt[1] + cnt[4] + cnt[7]; 
        int b2 = cnt[2] + cnt[5] + cnt[8]; 
        int t = (b1 + 2 * b2) % 3;
        if (t == 1) { 
            if (b1 >= 1) b1 -= 1;
            else b2 -= 2;
        } else if (t == 2) { 
            if (b2 >= 1) b2 -= 1;
            else b1 -= 2;
        }

        StringBuilder res = new StringBuilder();
        for (int d = 9; d >= 0; d--) {
            if (d % 3 == 0) while (cnt[d]-- > 0) res.append(d);
            else if (d % 3 == 1) while (cnt[d]-- > 0 && b1-- > 0) res.append(d);
            else while (cnt[d]-- > 0 && b2-- > 0) res.append(d);
        }
        if (res.length() > 0 && res.charAt(0) == '0') return "0"; 
        return res.toString();
    }
}