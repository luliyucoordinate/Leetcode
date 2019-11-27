class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);
        List<List<String>> res = new ArrayList();
        int l = 0, r = products.length - 1;
        
        for (int i = 0; i < searchWord.length(); i++) {
            while (l <= r && (products[l].length() <= i || products[l].charAt(i) != searchWord.charAt(i))) l++;
            while (l <= r && (products[r].length() <= i || products[r].charAt(i) != searchWord.charAt(i))) r--;
            List<String> tmp = new ArrayList();
            for (int j = l; j < Math.min(l+3, r+1); j++)
                tmp.add(products[j]);
            res.add(tmp);
        } 
        return res;
    }
}