class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private boolean[] st;
  
    public List<List<Integer>> permute(int[] nums) {
        st = new boolean[nums.length];
        dfs(new ArrayList<>(), nums);
        return res;
    }
    
    private void dfs(List<Integer> path, int[] nums) {
        if (path.size() == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }
      
        for (int i = 0; i < nums.length; i++) {
            if (st[i]) continue;
            st[i] = true;
            path.add(nums[i]);
            dfs(path, nums);
            path.remove(path.size() - 1);
            st[i] = false;
        }
    }
}
