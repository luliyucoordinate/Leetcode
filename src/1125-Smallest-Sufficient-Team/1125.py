from functools import lru_cache
class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        key = {skill: i for i, skill in enumerate(req_skills)}
        people_skill = [0 for _ in range(len(people))] 
        skill_people = [[] for _ in range(len(req_skills))] 
        for i, p in enumerate(people):
            for skill in p:
                if skill in key:
                    people_skill[i] |= 1 << key[skill]
                    skill_people[key[skill]].append(i)
        
        def first_set_bit(n: int) -> int:
            return int(math.log2(n & -n)) #low bit
        
        @lru_cache()
        def dfs(skills_wanted: int) -> List[int]:
            if skills_wanted == 0:
                return []
            
            smallest_team_size = float('inf')
            res = []
            
            target_skill = first_set_bit(skills_wanted)
            
            for p in skill_people[target_skill]:
                cand_skills_wanted = skills_wanted
                cand_skills_wanted &= ~people_skill[p]
                cand = [p] + dfs(cand_skills_wanted)
                if len(cand) < smallest_team_size:
                    smallest_team_size = len(cand)
                    res = cand
            
            return res
        
        return dfs((1 << len(req_skills)) - 1)