class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int[] arrs = new int[arr.length];
        arrs = arr.clone();
        
        Arrays.sort(arrs);
        Map<Integer, Integer> st = new HashMap();
        for (int i = 0; i < arrs.length; i++) {
            st.putIfAbsent(arrs[i], st.size() + 1);
        }
        
        for (int i = 0; i < arr.length; i++) {
            arr[i] = st.get(arr[i]);
        }
        return arr;
    }
}