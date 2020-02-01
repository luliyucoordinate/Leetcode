var filterRestaurants = function(restaurants, veganFriendly, maxPrice, maxDistance) {
    return restaurants
        .filter(s => s[2] >= veganFriendly && s[3] <= maxPrice && s[4] <= maxDistance)
        .sort((a, b) => b[1] - a[1] || b[0] - a[0])
        .map(s => s[0]);
};