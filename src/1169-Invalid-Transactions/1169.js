var invalidTransactions = function(transactions) {
    let data = {}, delt = {};
    for (let i in transactions) {
        let it = transactions[i].split(",");
        if (Number(it[2]) > 1000) {
            delt[i] = 0;
        }
        if (data[it[0]])
            data[it[0]].push([Number(it[1]), it[3], i]);
        else data[it[0]] = [[Number(it[1]), it[3], i]];
    }
    
    for (let k in data) {
        data[k].sort((a, b) => a[0] - b[0]);
        let q = [];
        for (let it of data[k]) {
            while (q.length > 0 && q[0][0] < it[0] - 60) {
                q.shift();
            }
            for (let ix of q) {
                if (it[1] != ix[1]) {
                    delt[it[2]] = 0;
                    delt[ix[2]] = 0;
                }
            }
            q.push(it);
        }
    }
    let res = [];
    for (let k in delt) {
        res.push(transactions[k]);
    }
    return res;
};