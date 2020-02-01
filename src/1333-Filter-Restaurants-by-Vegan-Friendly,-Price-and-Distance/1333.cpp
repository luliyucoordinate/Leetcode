class Solution 
{
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) 
    {
        restaurants.erase(remove_if(restaurants.begin(), restaurants.end(), [=](auto const s) {
            return !(s[2] >= veganFriendly && s[3] <= maxPrice && s[4] <= maxDistance);
        }), restaurants.end());
        
        sort(restaurants.begin(), restaurants.end(), [](auto const a, auto const b) {
            return a[1] == b[1] ? a[0] > b[0]: a[1] > b[1];
        });
        
        vector<int> res(restaurants.size());
        transform(restaurants.begin(), restaurants.end(), res.begin(), [](auto const s) {
            return s[0];
        });
        return res;
    }
};