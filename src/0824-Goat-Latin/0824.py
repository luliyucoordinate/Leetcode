class Solution:
    def toGoatLatin(self, S: str) -> str:
        res, vowels = [], set("aeiouAEIOU")
        S = S.split(" ")
        for i, w in enumerate(S):
            if w[0] not in vowels:
                w = w[1:] + w[0]
            res.append(w + "ma" + (i + 1) * "a")
        return " ".join(res)