class Solution:
    def removeVowels(self, S: str) -> str:
        return re.sub(r'[aeiou]', '', S)