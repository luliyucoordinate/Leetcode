class Solution {
    public String entityParser(String text) {
        Map<String, String> entity = new HashMap();
        entity.put("&amp", "&");
        entity.put("&quot", "\"");
        entity.put("&apos", "'");
        entity.put("&gt", ">");
        entity.put("&lt", "<");
        entity.put("&frasl", "/");
        
        StringBuilder res = new StringBuilder();
        int n = text.length(), i = 0;
        while (i < n) {
            if (text.charAt(i) == '&') {
                StringBuilder t = new StringBuilder();
                while (text.charAt(i) != ';') {
                    t.append(text.charAt(i));
                    i++;
                }
                
                String cur = t.toString();
                if (entity.containsKey(cur)) res.append(entity.get(cur));
                else res.append(cur).append(";");
            } else res.append(text.charAt(i));
            i++;
        }
        return res.toString();
    }
}