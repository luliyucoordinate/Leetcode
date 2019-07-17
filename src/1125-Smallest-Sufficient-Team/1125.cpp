class Solution 
{
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people)
    {
        unordered_map<string, int> key;
        for (int i = 0; i < req_skills.size(); ++i) key[req_skills[i]] = i;
        vector<int> people_skill(people.size(), 0);
        vector<vector<int>> skill_people(req_skills.size());
        for (int i = 0; i < people.size(); ++i)
        {
            for (string skill : people[i])
            {
                if (key.count(skill))
                {
                    people_skill[i] |= 1 << key[skill];
                    skill_people[key[skill]].push_back(i);
                }
            }
        }
        return dfs((1 << req_skills.size()) - 1, people_skill, skill_people);
    }
    
    
    unordered_map<int, vector<int>> smallest_team = {{0, {}}};    
    vector<int> dfs(int skills_wanted,  vector<int>& people_skill, vector<vector<int>>& skill_people)
    {
        if (smallest_team.count(skills_wanted)) return smallest_team[skills_wanted];
        int smallest_team_size = INT_MAX;
        vector<int> res;
        int target_skill = int(log2(skills_wanted & -skills_wanted));
        for (int p : skill_people[target_skill])
        {
            int cand_skills_wanted = skills_wanted & ~people_skill[p];
            auto pre = dfs(cand_skills_wanted, people_skill, skill_people);
            pre.push_back(p);
            if (pre.size() < smallest_team_size) 
            {
                smallest_team_size = pre.size();
                res = pre;
            }
        }
        smallest_team[skills_wanted] = res;
        return res;
    }
};