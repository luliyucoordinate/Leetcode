const int M = 50010;
int son[M][27], nodes[M], idx;

void insert(string str) {
    int p = 0;
    for (char c : str) {
        int& s = son[p][c - 'a'];
        if (!s) s = ++idx;
        son[s][26]++;
        p = s;
    }
}

bool get(string& str) {
    int p = 0, s;
    for (char c : str) {
        s = son[p][c - 'a'];
        if (!s) return false;
        p = s;
    }
    return son[s][26] > 1;
}

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        memset(son, 0, sizeof son);
        memset(nodes, 0, sizeof nodes);
        idx = 0;
        
        for (string& word : words) {
            for (int i = 0; i < word.size(); i++) {
                insert(word.substr(i));
            }
        }
        
        vector<string> res;
        for (string& word : words) {
            if (get(word)) res.emplace_back(word);
        }
        return res;
    }
};