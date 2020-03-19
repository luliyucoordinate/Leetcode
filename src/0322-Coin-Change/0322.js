var coinChange = function(coins, amount) {
    coins.sort((a, b) => b - a);
    let res = amount + 1;

    let dfs = function(index, cur, cnt) {
        let coins_i = coins[index];
        if (cnt + Math.ceil(cur / coins_i) >= res) return;

        if (cur % coins_i == 0) {
            res = cnt + Math.floor(cur / coins_i);
            return ;
        } 

        if (index == coins.length - 1) return ;

        for (let i = Math.floor(cur / coins_i); i >= 0; i--) 
            dfs(index + 1, cur - coins_i * i, cnt + i);
    }

    dfs(0, amount, 0);
    return res > amount ? -1 : res;
};