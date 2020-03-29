const int M = 15000;
int son[M][26], nodes[M], idx;

void insert(string& str, int id) {
    int p = 0;
    for (int i = str.size() - 1; ~i; i--) {
        int& s = son[p][str[i] - 'a'];
        if (!s) s = ++idx;
        p = s;
    }
    nodes[p] = id;
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        memset(son, 0, sizeof son);
        memset(nodes, 0, sizeof nodes);
        idx = 0;
        for (int i = 0; i < words.size(); i++) insert(words[i], i + 1);

        int res = 0;
        for (int i = 1; i <= idx; i++) {
            if (nodes[i] == 0) continue;
            bool flag = false;
            for (int j = 0; j < 26; j++) {
                if (son[i][j]) {
                    flag = true; 
                    break;
                }
            }
            if (!flag) res += words[nodes[i] - 1].size() + 1;
        }
        return res;
    }
};