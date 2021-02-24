class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            int l = 0, r = A[0].size() - 1;
            while (l < r) {
                if (A[i][l] == A[i][r]) {
                    A[i][l] ^= 1;
                    A[i][r] ^= 1;
                } 
                l++, r--;
            }
            if (l == r) {
                A[i][l] ^= 1;
            }
        }
        return A;
    }
};