class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder res = new StringBuilder(s);
        Stack<Integer> st = new Stack();
        for (int i = 0; i < res.length(); ++i) {
            if (res.charAt(i) == '(') st.add(i + 1);
            else if (res.charAt(i) == ')') {
                if (!st.empty() && st.peek() >= 0) st.pop();
                else st.add(~i);
            }
        }
        while (!st.empty()) res.deleteCharAt(Math.abs(st.pop()) - 1);
        return res.toString();
    }
}