var t, n, s int
var vis []int

func canPartitionKSubsets(nums []int, k int) bool {
    n, s = len(nums), 0
    for _, v := range nums {
        s += v
    }
    
    if s % k > 0 {
        return false
    }
    
    t = s / k
    vis = make([]int, n)
    sort.Sort(sort.Reverse(sort.IntSlice(nums)))
    return dfs(nums, 0, 0, 0, k)
}

func dfs(nums []int, cur, u, p, k int) bool {
    if u == k {
        return true
    }
    if cur == t {
        return dfs(nums, 0, u + 1, 0, k)
    }
    
    for i, j := p, 0; i < n; i++ {
        if vis[i] == 1 || nums[i] + cur > t {
            continue
        }
        
        vis[i] = 1
        if dfs(nums, nums[i] + cur, u, i + 1, k) {
            return true
        }
        vis[i] = 0
        
        if cur == 0 || cur + nums[i] == t {
            return false
        }
        
        j = i
        for j < n && nums[i] == nums[j] {
            j++
        }
        i = j - 1
    }
    return false
}