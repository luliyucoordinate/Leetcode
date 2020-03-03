var validateStackSequences = function(pushed, popped) {
    let i = 0, j = 0;

    for (let num of pushed) {
        pushed[i] = num;
        i++;
        while (i > 0 && pushed[i - 1] == popped[j]) i--, j++;
    }
    
    return i == 0;
};