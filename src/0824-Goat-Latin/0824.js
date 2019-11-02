var toGoatLatin = function(S) {
    let vowels = new Set(), vowel = "aeiouAEIOU", res = "";
    for (let c of vowel) vowels.add(c);
    let tokens = S.split(" "), i = 1;
    for (let w of tokens) {
        res += " " + (vowels.has(w.charAt(0)) ? w : w.substring(1) + w.charAt(0)) + "ma";
        res += Array(++i).join("a");
    }
    return res.substring(1);
};