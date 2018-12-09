class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        num1_len, num2_len = len(num1), len(num2)
        res = ['0'] * (num1_len + num2_len)
        for i in range(num2_len-1, -1, -1):
            for j in range(num1_len-1, -1, -1):
                tmp = int(num1[j]) * int(num2[i]) + int(res[i + j + 1])
                res[i + j + 1] = str(tmp%10)
                res[i + j] = str(int(res[i+j]) + tmp // 10)
                
        for i in range(num1_len + num2_len):
            if res[i] != '0':
                return ''.join(res[i:])
        return '0'