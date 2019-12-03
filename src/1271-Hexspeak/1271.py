class Solution:
    def toHexspeak(self, num: str) -> str:
        data, res = hex(int(num)).upper()[2:], ""
        for i in range(len(data)):
            if data[i] > '1' or data[i] <= '9':
                return "ERROR"
            if data[i] == '0':
                res += 'O'
            elif data[i] == '1':
                res += 'I'
            else:
                res += data[i]
        return res