var invalidTransactions = function(transactions) {
    let data = new Map(), delt = new Map();
    for (let i in transactions) {
        let it = transactions[i].split(",");
        if (Number(it[2]) > 1000) {
            delt.set(i, 0)
        }
        if (data.has(it[0]))
            data.get(it[0]).push([Number(it[1]), it[3], i]);
        else data.set(it[0], [[Number(it[1]), it[3], i]]);
    }
    
    for (let [k, v] of data) {
        data.get(k).sort((a, b) => a[0] - b[0]);
        let q = [];
        for (let it of data.get(k)) {
            while (q.length > 0 && q[0][0] < it[0] - 60) {
                q.shift();
            }
            for (let ix of q) {
                if (it[1] != ix[1]) {
                    delt.set(it[2], 0)
                    delt.set(ix[2], 0)
                }
            }
            q.push(it);
        }
    }
    let res = [];
    for (let [k, v] of delt) {
        res.push(transactions[k]);
    }
    return res;
};