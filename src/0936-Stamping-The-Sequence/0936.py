class Solution:
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        t_len, s_len = len(target), len(stamp)
        mem = dict()

        def dfs(i, j, paths):
            if (i, j) in mem:
                return mem[(i, j)]

            if i == t_len:
                return paths if j == s_len else []
            
            res = []
            if j == s_len:
                for k in range(s_len):
                    res = dfs(i, k, [i - k] + paths)
                    if res:
                        break
            elif target[i] == stamp[j]:
                res = dfs(i + 1, j + 1, paths) or dfs(i + 1, 0, paths + [i + 1])
            mem[(i, j)] = res
            return res

        return dfs(0, 0, [0])

if __name__ == "__main__":
    stamp = "abc"
    target = "ababc"
    print(Solution().movesToStamp(stamp, target))