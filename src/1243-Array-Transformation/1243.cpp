class Solution 
{
public:
    vector<int> transformArray(vector<int>& arr) 
    {
        bool change = true;
        vector<int> tmp = arr;
        while (change) 
        {
            change = false;
            for (int i = 1; i < arr.size() -1; i++) 
            {
                if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) 
                {
                    tmp[i]--; change = true;
                }
                else if (arr[i] < arr[i-1] && arr[i] < arr[i+1])
                {
                    tmp[i]++; change = true;
                } 
            }
            arr = tmp;
        }
        return arr;
    }
};