class Solution 
{
public:
    int oddEvenJumps(vector<int>& A) 
    {
        int n = A.size();
        vector<int> d(n);
        for (int i = 0; i < n; i++) d[i] = i;
        stable_sort(d.begin(), d.end(), [&](const int i, const int j){
            return A[i] < A[j];
        });
        vector<int> n1 = st(d);
        stable_sort(d.begin(), d.end(), [&](const int i, const int j){
            return A[i] > A[j];
        });
        vector<int> n2 = st(d);
        
        vector<int> h(n), l(n);
        h[n-1] = l[n-1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            h[i] = l[n1[i]];
            l[i] = h[n2[i]];
        }
        return accumulate(h.begin(), h.end(), 0);
    }
private:
    vector<int> st(vector<int>& data)
    {
        int n = data.size();
        vector<int> s, res(n);
        for (int i : data)
        {
            while (!s.empty() and s.back() < i)
            {
                res[s.back()] = i;
                s.pop_back();
            }
            s.push_back(i);
        }
        return res;
    }
};