class Solution {
    public List<Integer> transformArray(int[] arr) {
        Boolean change = true;
        int[] tmp = arr.clone();
        while (change) {
            change = false;
            for (int i = 1; i < arr.length -1; i++) {
                if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                    tmp[i]--; change = true;
                } else if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                    tmp[i]++; change = true;
                } 
            }
            arr = tmp.clone();
        }
        List<Integer> res = new ArrayList();
        for (int i : arr) res.add(i);
        return res;
    }
}