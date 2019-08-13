class MajorityChecker 
{
public:
    MajorityChecker(vector<int>& arr) 
    {
        data = arr;
        for(int i = 0; i < arr.size(); ++i)  indexs[data[i]].push_back(i);
    }
    
    int query(int left, int right, int threshold) 
    {
        for(int i = 0; i < 7; ++i) 
        {
            int x = left + rand() % (right - left + 1);
            int num = data[x];
            auto l = lower_bound(indexs[num].begin(), indexs[num].end(), left);
            auto r = upper_bound(indexs[num].begin(), indexs[num].end(), right);
            if (r - l >= threshold) return num;
        }
        return -1;
    }
private:
    vector<int> data;
    unordered_map<int, vector<int>> indexs;
};