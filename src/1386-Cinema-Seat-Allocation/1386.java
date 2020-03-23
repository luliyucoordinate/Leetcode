class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, Integer> cnt = new HashMap();
        for (int[] t : reservedSeats) {
            cnt.put(t[0], cnt.getOrDefault(t[0], 0) | 1 << (t[1] - 1));
        }
        
        int res = 0, q1 = 0b111111110, q2 = 0b111100000, q3 = 0b000011110, q4 = 0b001111000;
        for (int v : cnt.values()) {
            if ((q1 & v) == 0) res += 2;
            else if ((q2 & v) == 0 || (q3 & v) == 0 || (q4 & v) == 0) res++;
        }
        return res + (n - cnt.size()) * 2;
    }
}