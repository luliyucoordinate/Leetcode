/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(isNegative(x)){return false}
    var z = x.toString().split("").reverse().join("");
    if(x.toString()===z){return true}
    else{
    return false
    }
};

const isNegative = (y) =>{
    if(y < 0){return true}
    return false;
}
