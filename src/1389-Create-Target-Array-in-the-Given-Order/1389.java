class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        List<Integer> data = new ArrayList<>(nums.length);
        for (int i = 0; i < nums.length; i++) {
            data.add(index[i], nums[i]);
        }
        
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            res[i] = data.get(i);
        }
        return res;
    }
}