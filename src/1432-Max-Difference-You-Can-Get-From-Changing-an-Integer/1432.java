class Solution {
    public int maxDiff(int num) {
        String a = Integer.toString(num), b = a;
        for (int i = 0; i < a.length(); i++) {
            char digit = a.charAt(i);
            if (digit != '9') { 
                a = a.replace(digit, '9');
                break;
            }
        }
        
        if (b.charAt(0) != '1') {
            b = b.replace(b.charAt(0), '1');
        } else {
            for (int i = 1; i < b.length(); i++) {
                char bi = b.charAt(i);
                if (bi != '0' && bi != '1') {
                    b = b.replace(bi, '0');
                    break;
                }
            }
        }
        return Integer.parseInt(a) - Integer.parseInt(b);
    }
}