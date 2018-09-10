class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
            return {};
        
        std::sort(nums.begin(), nums.end());

        std::unordered_map<long long, std::vector<std::pair<int, int>>> um;
        for (int i = nums.size() - 1; i > 0; --i)
        {
            if (i < nums.size() - 1 && nums[i] == nums[i + 1])
                continue;
            for (int j = i - 1; j >= 0; --j)
            {
                if (i - j > 1 && nums[j] == nums[j + 1])
                    continue;
                um[nums[i] + nums[j]].push_back({j, i});
            }
        }

        std::vector<std::vector<int>> ret;
        for (unsigned i = 0; i < nums.size() - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (unsigned j = i + 1; j < nums.size() - 2; ++j)
            {
                if (j - i > 1 && nums[j] == nums[j - 1])
                    continue;
                long long s = static_cast<long long>(nums[i]) + nums[j];
                auto it = um.find(target - s);
                if (it == um.end())
                    continue;
                for (auto p : it->second)
                    if (p.first > j)
                        ret.push_back({nums[i], nums[j], nums[p.first], nums[p.second]});
            }
        }
        
        return ret;
    }
};