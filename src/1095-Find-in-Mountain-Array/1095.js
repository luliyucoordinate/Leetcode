var findInMountainArray = function(t, MountainArray) {
    var p = 0, r = MountainArray.length() - 1;
    while (p < r) {
        var mid = (p + r) >> 1;
        if (MountainArray.get(mid) > MountainArray.get(mid + 1)) r = mid;
        else p = mid + 1;
    }
    function bs(l, r, asc) {
        while (l < r) {
            var mid = (l + r) >> 1;
            if ((asc && MountainArray.get(mid) >= t) || (!asc && MountainArray.get(mid) <= t)) r = mid;
            else l = mid + 1;
        }
        if (MountainArray.get(l) == t) return l;
        return -1;
    }
    var i = bs(0, p, true);
    return i != -1 ? i : bs(p+1, MountainArray.length()-1, false);
};