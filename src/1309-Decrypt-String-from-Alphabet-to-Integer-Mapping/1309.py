class Solution:
    def freqAlphabets(self, s: str) -> str:
        return ''.join(chr(int(i[:2]) + 96) for i in re.findall(r'\d\d#|\d', s))