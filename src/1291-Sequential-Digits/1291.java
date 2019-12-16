class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> res = new ArrayList();
        for (int i = 1; i < 9; i++) {
            int x = i;
            while (x <= high) {
                int r = x % 10;
                if (r == 0) break;
                if (x >= low) res.add(x);
                x = x * 10 + r + 1;
            }
        }
        Collections.sort(res);
        return res;
    }
}