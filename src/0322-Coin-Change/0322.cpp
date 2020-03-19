class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        res = amount + 1;
        dfs(coins, 0, amount, 0);
        return res > amount ? -1 : res;
    }
private:
    long long res;
    void dfs(vector<int>& coins, int index, long long target, long long cnt) {
        if (cnt + (target + coins[index] - 1) / coins[index] >= res) return;

        if (target % coins[index] == 0) {
            res = cnt + target / coins[index];
            return;
        }

        if (index == coins.size() - 1) return;

        for (int i = target / coins[index]; i >= 0; i--)
            dfs(coins, index + 1, target - coins[index] * i, cnt + i);
    }
};