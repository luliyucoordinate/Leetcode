class Solution {
    public int[] closestDivisors(int num) {
        for (int a = (int)Math.sqrt(num + 2); a > 0; --a) {
            if ((num + 1) % a == 0)
                return new int[]{a, (num + 1) / a};
            if ((num + 2) % a == 0)
                return new int[]{a, (num + 2) / a};
        }
        return new int[]{};
    }
}