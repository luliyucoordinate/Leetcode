class Solution {
    public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        return Arrays.stream(restaurants)
            .filter(s -> s[2] >= veganFriendly && s[3] <= maxPrice && s[4] <= maxDistance)
            .sorted((a, b) -> a[1] == b[1] ? b[0] - a[0] : b[1] - a[1])
            .map(i -> i[0])
            .collect(Collectors.toList());
    }
}