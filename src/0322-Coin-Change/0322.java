class Solution {
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        res = amount + 1;
        dfs(coins, coins.length - 1, amount, 0);
        return (int)res > amount ? -1 : (int)res;
    }

    private long res;

    private void dfs(int[] coins, int index, long cur, long cnt) {
        long coins_i = coins[index];
        if (cnt + (cur + coins_i - 1) / coins_i >= res) return;

        if (cur % coins_i == 0) {
            res = cnt + cur / coins_i;
            return ;
        } 

        if (index == 0) return ;

        for (long i = cur / coins_i; i >= 0; i--) 
            dfs(coins, index - 1, cur - coins_i * i, cnt + i);
    }
}