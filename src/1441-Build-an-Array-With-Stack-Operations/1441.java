class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> res = new ArrayList();
        int k = 1;
        for (int i = 0; i < target.length; i++, k++) {
            if (target[i] == k) { 
                res.add("Push");
            } else { 
                i--;
                res.add("Push");
                res.add("Pop");
            }
        }
        return res;
    }
}