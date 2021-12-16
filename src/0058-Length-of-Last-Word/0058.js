/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let x = s.trim(); //this will ignore the spaces at start and end of the string.
    let len = x.length;//always take length like this intead of putting in it into for loop //dirctl coz when you put it into for loop it will call for length again and again.
    let cnt = 0;
    for(let i = 0; i<=len-1;i++){
        if(x[i]===" "){
            cnt = 0;
        }
        else{
            cnt++;
        }
    }
    return cnt;//returns the length of the word at last in string.
};
//up vote this if you got something from this Happy Coding....</>
