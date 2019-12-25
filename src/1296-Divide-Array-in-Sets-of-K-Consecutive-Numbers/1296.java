class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if (nums.length % k != 0) return false;
        Arrays.sort(nums);
        Map<Integer, Integer> cnt = new HashMap();
        for (int i : nums) {
            cnt.put(i, cnt.getOrDefault(i, 0) + 1);
        }
        
        for (int i : nums) {
            int t = cnt.get(i);
            if (t > 0) {
                for (int j = i; j < i + k; j++) {
                    int pre = cnt.getOrDefault(j, 0);
                    if (pre < t) return false;
                    cnt.put(j, pre - t);
                }
            }
        }
        return true;
    }
}