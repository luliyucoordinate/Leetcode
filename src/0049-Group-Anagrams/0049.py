class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        strs_map = {}
        result = []
        for string in strs:
            tmp = ''.join(sorted(string))
            if tmp in strs_map:
                strs_map[tmp].append(string)
            else:
                strs_map[tmp] = [string]
                
        for str_list in strs_map.values():
            result.append(str_list)
        
        return result


if __name__ == "__main__":
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(Solution().groupAnagrams(strs))