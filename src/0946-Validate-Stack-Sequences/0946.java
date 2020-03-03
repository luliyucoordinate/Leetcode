class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int i = 0, j = 0;

        for (int num : pushed) {
            pushed[i] = num;
            i++;
            while (i > 0 && pushed[i - 1] == popped[j]) {
                i--;
                j++;
            }
        }
        
        return i == 0;
    }
}