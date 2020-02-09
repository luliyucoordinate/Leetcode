class Solution {
    public int numberOfSteps (int num) {
        return num == 0 ? 0 : 1 + numberOfSteps(num % 2 == 1 ? num - 1 : num >> 1);
    }
}