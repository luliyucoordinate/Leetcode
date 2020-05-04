class Solution {
    public int constrainedSubsetSum(int[] nums, int k) {
        Deque<Integer> q = new ArrayDeque();
        int res = -10000, n = nums.length;

        for (int i = 0; i < n; i++) {
            nums[i] = Math.max(nums[i], nums[i] + (q.isEmpty() ? 0 : q.peek()));
            while (!q.isEmpty() && nums[i] > q.peekLast()) q.pollLast();
            q.offer(nums[i]);

            if (i >= k && !q.isEmpty() && q.peek() == nums[i - k]) q.poll();
            res = Math.max(res, nums[i]);
        }
        return res;
    }
}