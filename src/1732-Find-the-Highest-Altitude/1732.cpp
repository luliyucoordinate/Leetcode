class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> v;
        int first=0;
        v.push_back(first);
        for(int i = 0 ; i < gain.size() ; i++)
        {
            first += gain[i];
            v.push_back(first);
        }
        int result = *max_element(v.begin(), v.end());
        return result;
    }
};
