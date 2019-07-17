import "math"
var people_skill []int
var skill_people [][]int
var smallest_team map[int][]int
func smallestSufficientTeam(req_skills []string, people [][]string) []int {
    key := make(map[string]int)
    for i, v := range req_skills {
        key[v] = i
    }
    people_skill = make([]int, len(people))
    skill_people = make([][]int, len(req_skills))
    for i, v := range people {
        for _, skill := range v {
            if _, ok := key[skill]; ok {
                people_skill[i] |= (1 << uint(key[skill]));
                skill_people[key[skill]] = append(skill_people[key[skill]], i)
            }
        }
    }
    smallest_team = map[int][]int{0:{}}
    return dfs((1 << uint(len(req_skills))) -1)
}

func dfs(skills_wanted int) []int {
    if v, ok := smallest_team[skills_wanted]; ok {
        return v
    }
    smallest_team_size := 61
    res := []int{}
    target_skill := int(math.Log2(float64(skills_wanted & -skills_wanted)))
    for _, p := range skill_people[target_skill] {
        cand_skill_wanted := skills_wanted &^ people_skill[p]
        pre := dfs(cand_skill_wanted)
        pre = append(pre, p)
        if len(pre) < smallest_team_size {
            smallest_team_size = len(pre)
            res = pre
        }
    }
    smallest_team[skills_wanted] = res
    return res
}