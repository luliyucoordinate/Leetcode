class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = list()
        match = {'{':'}', '[':']', '(':')'}
        for i in s:
            if i == '{' or i == '(' or i == '[':
                stack.append(i)
            else:
                if len(stack) == 0:
                    return False

                top = stack.pop()
                
                if match[top] != i:
                    return False

        if len(stack) != 0:
            return False
        return True


        

if __name__ == "__main__":
    s = "()"
    print(Solution().isValid(s))