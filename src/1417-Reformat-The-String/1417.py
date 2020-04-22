class Solution:
    def reformat(self, s: str) -> str:
        nums, chars = [], []
        for i in s:
            if '0' <= i <= '9': nums.append(i)
            else: chars.append(i)
                
        if abs(len(nums) - len(chars)) > 1: return ""
        res = ""
        flag = True if len(nums) >= len(chars) else False
        for _ in range(len(s)):
            if flag: res += nums.pop()
            else: res += chars.pop()
            flag = not flag
        return res