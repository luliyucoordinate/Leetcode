var entityParser = function(text) {
    let res = "", n = text.length, i = 0;
    let entity = {
        '&quot': '\"',
        '&apos': "'",
        '&gt': '>',
        '&lt': '<',
        '&frasl': '/', 
        '&amp': '&',
    };
    
    while (i < n) {
        if (text[i] == '&') {
            let t = "";
            while (text[i] != ';') {
                t += text[i++];
            }

            if (t in entity) res += entity[t];
            else res += t + ";";
        } else res += text[i];
        i++;
    }
    return res;
};