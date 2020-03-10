class Solution {
    public String generateTheString(int n) {
        return "a".repeat(n - 1) + (n % 2 == 1 ? "a" : "b");
    }
}