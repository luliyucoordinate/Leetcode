class Solution {
    public List<String> printVertically(String s) {
        String[] strs = s.split(" ");
        int max_len = 0;
        for (String st : strs) max_len = Math.max(max_len, st.length());
        
        List<String> res = new ArrayList();
        for (int j = 0; j < max_len; j++) {
            StringBuilder t = new StringBuilder();
            int t_len = 0;
            
            for (String st : strs) {
                if (st.length() > j) {
                    t.append(st.charAt(j));
                    t_len = t.length();
                } else t.append(" ");
            }
            t.setLength(t_len);
            res.add(t.toString());
        }
        return res;
    }
}