class Solution {
    public List<Integer> numOfBurgers(int t, int c) {
        return t % 2 == 0 && c * 2 <= t && t <= c * 4 ? Arrays.asList(t / 2 - c, c * 2 - t / 2) : new ArrayList();
    }
}