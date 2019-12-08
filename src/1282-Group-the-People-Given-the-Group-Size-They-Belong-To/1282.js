/**
 * @param {number[]} groupSizes
 * @return {number[][]}
 */
var groupThePeople = function(a) {
    let res = [], data = new Map();
    for (let i = 0; i < a.length; i++) {
        if (!data.has(a[i])) data.set(a[i], []);
        data.get(a[i]).push(i);
        if (data.get(a[i]).length == a[i]) {
            res.push(data.get(a[i]));
            data.set(a[i], []);
        }
    }
    return res;
};