class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] A = new int[arr.length + 1];
        for (int i = 1; i <= arr.length; i++) {
            A[i] = A[i - 1] ^ arr[i - 1];
        } 
        
        int[] res = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            res[i] = A[queries[i][0]] ^ A[queries[i][1] + 1];
        }
        return res;
    }
}