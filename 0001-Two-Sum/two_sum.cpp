#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.count(target - nums[i]))
            {
                return { m[target - nums[i]] , i };
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
int main()
{
    const int nums[] = { 0,4,3,0 };
    vector<int> nums_vec(nums, nums + sizeof(nums) / sizeof(int));
    int target = 7;
    for (int v : Solution().twoSum(nums_vec, target))
    {
        std::cout << v << std::endl;
    }
    return 0;
}
template<class K, class E>
void hashTable<K, E>::erase(const K& theKey)
{
    int b = search(theKey);
    if (table[b] == nullptr || table[b]->first != theKey) return;
    int i = (int)hash(theKey) % divisor;
    int j = i + 1;
    do
    {
        if ((int)hash(table[j]->first) % divisor == j) break;
        table[j - 1]->first = table[j]->first;
        table[j - 1]->second = table[j]->second;
        j = (j + 1) % divisor;
    }while(table[j] != nullptr || table[j]->first != theKey);
    delete table[j];
    table[j] = nullptr;
}