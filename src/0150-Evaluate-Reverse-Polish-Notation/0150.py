class Solution:
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = list()
        oper = ['+', '-', '*', '/']
        for char in tokens:
            if char not in oper:
                stack.append(int(char))
            else:
                top1 = stack.pop()
                top2 = stack.pop()
                if char == '+':
                    stack.append(top2 + top1)
                elif char == '-':
                    stack.append(top2 - top1)
                elif char == '*':
                    stack.append(top2 * top1)
                elif char == '/':
                    stack.append(int(top2 / top1))

        return stack.pop()

if __name__ == "__main__":
    s = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
    print(Solution().evalRPN(s))