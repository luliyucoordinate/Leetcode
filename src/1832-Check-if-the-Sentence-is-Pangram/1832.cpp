class Solution {
 public:
    bool checkIfPangram(string sentence) {
        map<char,int> m;
        char a = 'a';
        for (int i = 0; i < 26; i++) {
            m.insert({a,0});
            a++;
        }
        for (auto i : sentence) {
            m[i]++;
        }
        for (auto i : m) {
            if (i.second == 0)
                return false;
        }
        return true;
    }
};
