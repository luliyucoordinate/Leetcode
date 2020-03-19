class Solution:
    def coinChange(self, coins, amount):
        coins.sort(reverse=True)
        n, res = len(coins), amount + 1

        def dfs(index, target, cnt):
            nonlocal res
            if cnt + (target + coins[index] - 1) // coins[index] >= res:
                return 

            if target % coins[index] == 0:
                res = cnt + target // coins[index]
                return

            if index == n - 1:
                return

            for i in range(target // coins[index], -1, -1):
                dfs(index + 1, target - coins[index] * i, cnt + i)

        dfs(0, amount, 0)
        return -1 if res > amount else res