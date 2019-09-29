var uniqueOccurrences = function(arr) {
    var m = {}, m_len = 0;
    for (let n of arr) {
        if (m[n]) m[n]++;
        else {
            m[n] = 1;
            m_len++;
        }
    }
    
    var s = new Set();
    for (let i in m) {
        s.add(m[i]);
    }
    return m_len == s.size;
};