class Solution {
    public int minSetSize(int[] arr) {
        int n = arr.length/2, total = 0, res = 0;
        Map<Integer, Integer> freq = new HashMap();
        Map<Integer, Integer> cnt = new TreeMap<>((a, b) -> b - a);
        for (int i : arr) freq.put(i, freq.getOrDefault(i, 0) + 1);
        for (int i : freq.values()) cnt.put(i, cnt.getOrDefault(i, 0) + 1);
        
        for (int i : cnt.keySet()) {
            int dif = n - total;
            int x = Math.min(cnt.get(i), (dif + i - 1) / i);
            res += x;
            total += x * i;
            if (total >= n) return res;
        }
        return res;
    }
}