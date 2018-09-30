import math
class Solution:
    def coinChange(self, coins, amount):
        coins.sort(reverse=True)
        len_coins, result = len(coins), amount+1

        def countCoins(index, target, count):
            nonlocal result
            if count + math.ceil(target/coins[index]) >= result:
                return 

            if target % coins[index] == 0:
                result = count + target//coins[index]
                return

            if index == len_coins - 1:
                return

            for i in range(target//coins[index], -1, -1):
                countCoins(index+1, target - coins[index]*i, count+i)

        countCoins(0, amount, 0)
        return -1 if result > amount else result

if __name__ == '__main__':
    coins = [1,2147483647]
    amount = 2
    print(Solution().coinChange(coins, amount))