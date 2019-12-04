class Solution {
    public String tictactoe(int[][] moves) {
        int[][] score = new int[2][8];
        int p = 0;
        for (int[] it : moves) {
            score[p][it[0]]++; score[p][it[1] + 3]++;
            score[p][6] += (it[0] == it[1] ? 1 : 0);
            score[p][7] += (it[0] + it[1] == 2 ? 1 : 0);
            for (int x : score[p])
                if (x == 3) return p == 0 ? "A" : "B";
            p ^= 1;
        }
        return moves.length == 9 ? "Draw" : "Pending";
    }
}