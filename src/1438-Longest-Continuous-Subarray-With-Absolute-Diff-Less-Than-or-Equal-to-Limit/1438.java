class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxq = new ArrayDeque();
        Deque<Integer> minq = new ArrayDeque();
        int i = 0;

        for (int a : nums) {
            while (maxq.size() > 0 && a > maxq.peekLast()) maxq.pollLast();
            while (minq.size() > 0 && a < minq.peekLast()) minq.pollLast();
            maxq.offer(a);
            minq.offer(a);

            if (maxq.getFirst() - minq.getFirst() > limit) {
                if (maxq.getFirst() == nums[i]) maxq.pollFirst();
                if (minq.getFirst() == nums[i]) minq.pollFirst();
                i++;
            }
        }
        return nums.length - i;
    }
}