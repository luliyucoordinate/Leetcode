class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        Deque<Integer> cur = new ArrayDeque();
        int carry = 0;
        int l1 = arr1.length;
        int l2 = arr2.length;
        
        while (carry != 0 || l1 > 0 || l2 > 0) {
            if (l1 > 0) {
                l1--;
                carry += arr1[l1];
            }
            if (l2 > 0) {
                l2--;
                carry += arr2[l2];
            }
            cur.offer(carry & 1);
            carry = -(carry >> 1);
        }
        
        while (cur.size() > 1 && cur.peekLast() == 0) cur.pollLast();
        int[] res = new int[cur.size()];
        for (int i = cur.size() - 1; i >= 0; i--) res[i] = cur.pollFirst();
        return res;
    }
}