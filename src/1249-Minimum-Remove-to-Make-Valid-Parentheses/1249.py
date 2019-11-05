class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        st = []
        for i, v in enumerate(s):
            if v == ')':
                if st and st[-1][0] == '(':
                    st.pop()
                    continue
                st.append([v, i])
            elif v == '(':
                st.append([v, i])
        
        res, pre = "", 0
        for v, i in st:
            res += s[pre:i]
            pre = i + 1
        else:
            res += s[pre:]
        return res