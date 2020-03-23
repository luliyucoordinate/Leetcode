class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr2);
        
        int res = 0;
        this.d = d;
        for (int x : arr1) {
            if (check(arr2, x)) res++;
        }
        return res;
    }
    
    private int d;
    
    private boolean check(int[] arr2, int x) {
        int l = 0;
        int r = arr2.length - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (Math.abs(arr2[mid] - x) <= d) return false;
            if (arr2[mid] > x) r = mid;
            else l = mid + 1;
        }
        return Math.abs(arr2[l] - x) > d;
    }
}