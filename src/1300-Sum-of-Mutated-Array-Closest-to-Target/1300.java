class Solution {
    public int findBestValue(int[] A, int target) {
        Arrays.sort(A);
        int maxv = A[A.length-1], t = 0;
        
        while (t < A.length && target >= A[t]*(A.length - t)) {
            target -= A[t++];
        }
        return t == A.length ? maxv : (int)(target*1.0/(A.length - t) + 0.49);
    }
}