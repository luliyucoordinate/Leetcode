class Solution:
    def _restoreIpAddresses(self, s, n, index, ip, result):
        if n == 0:
            if index == len(s):
                result.append(ip)
            return

        def isNum(num):
            if 0 <= int(num) <= 255 and str(int(num)) == num:
                return True
            return False

        for i in range(index+1, len(s) + 1):
            if isNum(s[index:i]):
                self._restoreIpAddresses(s, n - 1, i, s[index:i] if ip == "" else ip+'.'+s[index:i], result)
            else:
                break
                   
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result = list()
        if not s and  4 > len(s) > 12 :
            return result

        self._restoreIpAddresses(s, 4, 0, "", result)
        return result

if __name__ == '__main__':
    s = "1111"
    print(Solution().restoreIpAddresses(s))