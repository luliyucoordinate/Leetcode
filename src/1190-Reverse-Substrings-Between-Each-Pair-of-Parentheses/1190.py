class Solution:
    def reverseParentheses(self, s: str) -> str:
        st, pair = [], {}
        for i, c in enumerate(s):
            if c == '(':
                st.append(i)
            if c == ')':
                j = st.pop()
                pair[i], pair[j] = j, i
                
        res, i, d = "", 0, 1
        while i < len(s):
            if s[i] in '()':
                i = pair[i]
                d = -d
            else:
                res += s[i]
            i += d
        return res