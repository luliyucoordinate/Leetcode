class Solution {
    public String reformat(String s) {
        Queue<Character> digits = new ArrayDeque();
        Queue<Character> chars = new ArrayDeque();
        
        for(char c : s.toCharArray()) {
            if (Character.isDigit(c)) digits.add(c);
            else chars.add(c);
        }
        if (Math.abs(digits.size() - chars.size()) > 1) return "";
        
        StringBuilder res = new StringBuilder();
        boolean flag = digits.size() >= chars.size() ? true : false; 
        for (int i = 0; i < s.length(); i++){
            if (flag) res.append(digits.poll());
            else res.append(chars.poll());
            flag = !flag; 
        }
        return res.toString(); 
    }
}