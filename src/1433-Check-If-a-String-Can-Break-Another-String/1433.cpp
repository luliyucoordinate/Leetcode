class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int d1[26] = {}, d2[26] = {};
        for (char c : s1) d1[c - 'a']++;
        for (char c : s2) d2[c - 'a']++;
        
        return check(d1, d2) || check(d2, d1);
    }
private:
    bool check(int d1[], int d2[]) {
        int s = 0;
        for (int i = 0; i < 26; i++) {
            s += d1[i] - d2[i];
            if (s < 0) return false;
        }
        return true;
    }
}; 