class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num), b = a;
        for (char digit : a) {
            if (digit != '9') {
                replace(a.begin(), a.end(), digit, '9');
                break;
            }
        }
        
        if (b[0] != '1') {
            char c = b[0];
            replace(b.begin(), b.end(), c, '1');
        } else {
            for (int i = 1; i < b.size(); i++) {
                if (b[i] != '0' && b[i] != '1') {
                    char c = b[i];
                    replace(b.begin(), b.end(), c, '0');
                    break;
                }
            }
        }
        return stoi(a) - stoi(b);
    }
};