var checkIfExist = function(arr) {
    let seen = new Map();
    for (let i of arr) {
        if (seen.has(i * 2) || (i % 2 == 0 && seen.has(Math.floor(i / 2)))) return true;
        seen.set(i, 1);
    }
    return false;
};