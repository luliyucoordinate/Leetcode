class Solution:
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        i, name_len = 0, len(name)
        for j in range(len(typed)):
            if i < name_len and typed[j] == name[i]:
                i += 1
            elif j == 0 or typed[j] != typed[j-1]:
                return False

        return i == name_len


if __name__ == "__main__":
    name = "leelee"
    typed = "lleeelee"
    print(Solution().isLongPressedName(name, typed))