class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int s = 0, res = 0, t = k * threshold, n = arr.length;
        for (int i = 0; i < k - 1; i++) s += arr[i];
        
        for (int l = 0; l < n - k + 1; l++) {
            s += arr[l + k - 1];
            if (s >= t) ++res;
            s -= arr[l];
        }
        return res;
    }
}