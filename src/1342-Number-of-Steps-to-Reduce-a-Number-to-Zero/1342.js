var numberOfSteps = function(num) {
    return num == 0 ? 0 : 1 + numberOfSteps(num & 1 ? num - 1 : num >> 1);
};