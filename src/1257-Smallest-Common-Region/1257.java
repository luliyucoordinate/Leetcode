class Solution {
    public String findSmallestRegion(List<List<String>> regions, String region1, String region2) {
        Map<String, String> parent = new HashMap();
        for (List<String> region : regions) {
            Iterator<String> iter = region.iterator(); 
            String fa = iter.next();
            while (iter.hasNext()) {
                parent.put(iter.next(), fa);
            }
        }
        String n1 = region1, n2 = region2;
        while (!n1.equals(n2)) {
            n1 = parent.containsKey(n1) ? parent.get(n1) : region2;
            n2 = parent.containsKey(n2) ? parent.get(n2) : region1;
        }
        return n1;
    }
}