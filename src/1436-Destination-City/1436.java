class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> set = new HashSet();
        for (List<String> path : paths) {
            set.add(path.get(0));
        }
        for (List<String> path : paths) {
            if (!set.contains(path.get(1))) return path.get(1);
        }
        return "";
    }
}