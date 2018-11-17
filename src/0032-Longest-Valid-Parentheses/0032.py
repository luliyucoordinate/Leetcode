class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        s_len, stack = len(s), list()
        for i, ch in enumerate(s):
            if ch == '(':
                stack.append(i)
            elif stack and s[stack[-1]] == '(':
                stack.pop()
            else:
                stack.append(i)

        if not stack:
            return s_len

        stack = [-1] + stack + [s_len]
        for i,val in enumerate(stack[1:]):
            stack[i] = val - stack[i] - 1

        return max(stack[:-1])


                
if __name__ == "__main__":
    s = "(()))())("
    print(Solution().longestValidParentheses(s))