class Solution {
    public int[] replaceElements(int[] arr) {
        int max_right = -1;
        for (int i = arr.length - 1; i >= 0; i--) {
            max_right = Math.max(arr[i], arr[i] = max_right);
        }
        return arr;
    }
}