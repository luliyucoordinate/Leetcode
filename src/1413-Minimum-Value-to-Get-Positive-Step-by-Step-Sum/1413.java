class Solution {
    public int minStartValue(int[] nums) {
        int pref = 0, min_pref = 0;
        for (int i : nums) {
            pref += i;
            min_pref = Math.min(min_pref, pref);
        }
        return 1 - min_pref;
    }
}