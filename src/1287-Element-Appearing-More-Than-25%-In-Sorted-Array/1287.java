class Solution {
    public int findSpecialInteger(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i += n / 4 + 1) {
            int l = bs(arr, true, arr[i]), r = bs(arr, false, arr[i]);
            if (r - l > n / 4) return arr[i];
        }
        return -1;
    }
    
    private int bs(int[] arr, Boolean flag, int t) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = l + r >> 1;
            if (t < arr[mid] || (flag && t == arr[mid])) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}