class Solution:
    def calculate(self, s):
        st, op, r, l = [], 1, 0, 0
        for c in s:
            if c.isdigit():
                r = r * 10 + int(c)
            elif c in "+-":
                l += op * r
                r, op = 0, 1 if c == '+' else -1
            elif c == "(":
                st.append(l)
                st.append(op)
                op, l = 1, 0
            elif c == ")":
                l += op * r
                r = 0
                l = st.pop() * l + st.pop()
        return l + op * r