class Solution {
    public int findLucky(int[] arr) {
        int[] cnt = new int[501];
        for (int i : arr) cnt[i]++;
        
        for (int i = 500; i > 0; i--) {
            if (cnt[i] == i) return i;
        }
        return -1;
    }
}