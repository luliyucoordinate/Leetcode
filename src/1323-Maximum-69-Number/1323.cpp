class Solution 
{
public:
    int maximum69Number (int num) 
    {
        string nums = to_string(num);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == '6') 
            {
                nums[i] = '9';
                break;
            }
        }
        return stoi(nums);
    }
};