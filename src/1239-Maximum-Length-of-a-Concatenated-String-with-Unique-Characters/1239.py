class Solution:
    def maxLength(self, arr: List[str]) -> int:
        arr_len, res = len(arr), 0
        def dfs(index, path):
            nonlocal res
            lsp, lp = len(set(path)), len(path)
            if lp == lsp:
                res = max(res, lp)
            if index == arr_len or lp != lsp:
                return
            for i in range(index, arr_len):
                dfs(i + 1, path + arr[i])
        dfs(0, "")
        return res