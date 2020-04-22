var displayTable = function(orders) {
    let res = [], foods = [], hm = {};
    for (let order of orders) {
        let food = order[2];
        if (hm[food] == undefined) {
            foods.push(food);
            hm[food] = 0;
        }
    }

    foods.sort();
    hm = {};
    for (let i = 0; i < foods.length; i++) {
        hm[foods[i]] = i;
    }

    let a = Array(501);
    for (let order of orders) {
        let table = Number(order[1]);
        a[table] = a[table] || Array(foods.length).fill(0);
        a[table][hm[order[2]]]++;
    }
    foods.unshift("Table");
    res.push(foods);

    for (let i = 0; i < 501; i++) {
        if (a[i]) {
            let row = [String(i)];
            for (let j = 0; j < foods.length - 1; j++) {
                row.push(String(a[i][j]));
            }
            res.push(row);
        }
    }
    return res;
};