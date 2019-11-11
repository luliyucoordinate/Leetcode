class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        n = len(words)
        cnt = [0] * 26
        for c in letters:
            cnt[ord(c) - 97] += 1
            
        def dfs(i):
            if i == n:
                return 0
            res = max(0, dfs(i + 1))
            tmp, val = 0, True
            for c in words[i]:
                t = ord(c) - 97
                cnt[t] -= 1
                tmp += score[t]
                if cnt[t] < 0:
                    val = False
            if val:
                res = max(res, dfs(i + 1) + tmp)
            for c in words[i]:
                cnt[ord(c) - 97] += 1
            return res
        return dfs(0)