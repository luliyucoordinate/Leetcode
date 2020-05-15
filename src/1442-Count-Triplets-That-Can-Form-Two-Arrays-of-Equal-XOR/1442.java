class Solution {
    public int countTriplets(int[] arr) {
        int n = arr.length, res = 0, prefix = 0, c, t;
        Map<Integer, Integer> cnt = new HashMap(), total = new HashMap();
        cnt.put(0, 1);
        for (int i = 0; i < n; ++i) {
            prefix ^= arr[i];
            c = cnt.getOrDefault(prefix, 0);
            t = total.getOrDefault(prefix, 0);
            res += c * i - t;
            cnt.put(prefix, c + 1);
            total.put(prefix, t + i + 1);
        }
        return res;
    }
}