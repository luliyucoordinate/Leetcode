class Solution:
    def wordPattern(self, pattern, str_):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        str_map1, str_map2 = {}, {}
        str_list = str_.split(' ')

        str_list_len = len(str_list)
        p_list_len = len(pattern)
        if str_list_len != p_list_len:
            return False
        
        for i in range(p_list_len):
            if str_map1.get(pattern[i]) != str_map2.get(str_list[i]):
                return False
            str_map1[pattern[i]] = str_map2[str_list[i]] = i
        return True

if __name__ == "__main__":
    pattern = "abba"
    str_ = "dog dog dog dog"
    print(Solution().wordPattern(pattern, str_))