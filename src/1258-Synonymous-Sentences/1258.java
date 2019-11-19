class Solution {
    public List<String> generateSentences(List<List<String>> synonyms, String text) {
        for (List<String> it : synonyms) {
            String x = find(it.get(0)), y = find(it.get(1));
            if (!x.equals(y)) parent.put(x, y);
        }
        for (String k : parent.keySet()) {
            String fk = find(k);
            if (!data.containsKey(fk)) {
                data.put(find(k), new ArrayList(k));
            }
            data.get(fk).add(k);
        }
        
        String[] txt = text.split(" ");
        List<String> res = Arrays.asList("");
        for (String w : txt) {
            String fw = find(w);
            if (data.containsKey(fw)) {
                List<String> tmp = new ArrayList();
                for (String s : res) {
                    for (String v : data.get(fw)) {
                        tmp.add(s + " " + v);
                    }
                }
                res = tmp;
            } else {
                for (int i = 0; i < res.size(); i++) {
                    res.set(i, res.get(i) + " " + w);
                }
            }
        }
        
        for (int i = 0; i < res.size(); i++) {
            res.set(i, res.get(i).substring(1));
        }
        Collections.sort(res);
        return res;
    }
    
    private Map<String, String> parent = new HashMap();
    private Map<String, List<String>> data = new HashMap();
    
    private String find(String x) {
        if (!parent.containsKey(x)) parent.put(x, x);
        if (!x.equals(parent.get(x))) {
            parent.put(x, find(parent.get(x)));
        }
        return parent.get(x);
    }
}