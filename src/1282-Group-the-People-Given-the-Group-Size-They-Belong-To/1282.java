class Solution {
    public List<List<Integer>> groupThePeople(int[] a) {
        List<List<Integer>> res = new ArrayList();
        Map<Integer, List<Integer>> data = new HashMap();
        for (int i = 0; i < a.length; i++) {
            List<Integer> tmp = data.computeIfAbsent(a[i], k -> new ArrayList());
            tmp.add(i);
            if (tmp.size() == a[i]) {
                res.add(new ArrayList(tmp));
                tmp.clear();
            }
        }
        return res;
    }
}