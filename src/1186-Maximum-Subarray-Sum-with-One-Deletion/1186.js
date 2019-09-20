var maximumSum = function(arr) {
    var deleted = 0, notDeleted = 0, res = -1000;
    for (var i = 0; i < arr.length; ++i)
    {
        deleted = Math.max(deleted + arr[i], arr[i]);
        if (i) deleted = Math.max(deleted, notDeleted);
        notDeleted = Math.max(notDeleted + arr[i], arr[i]);
        res = Math.max(res, deleted);
    }
    return res;
};