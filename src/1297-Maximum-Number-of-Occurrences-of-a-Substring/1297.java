class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        char[] data = s.toCharArray();
        char[] chs = new char[256];
        int nq = 0, res = 0, l = minSize;
        Map<String, Integer> cnt = new HashMap();
        
        for (int r = 0; r < data.length; r++) {
            if (chs[data[r]]++ == 0) ++nq;
            if (l <= r) {
                if (--chs[data[r - l]] == 0) nq--;
            }
            
            if (l - 1 <= r && nq <= maxLetters) {
                String curStr = s.substring(r - l + 1, r + 1);
                int t = cnt.getOrDefault(curStr, 0) + 1;
                cnt.put(curStr, t);
                if (t > res) res = t;
            }
        }
        return res;
    }
}