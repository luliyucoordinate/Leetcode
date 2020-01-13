/* for java 8
class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> res = new ArrayList();
        for (int i = 0; i < nums.length; i += 2)
            for (int j = 0; j < nums[i]; ++j)
                res.add(nums[i + 1]);
        return res.stream().mapToInt(i -> i).toArray();
    }
}
*/

class Solution {
    public int[] decompressRLElist(int[] nums) {
        int len = 0;
        for(int i = 0; i < nums.length; i += 2) {
            len += nums[i];
        }
        
        int[] res = new int[len];
        int cur = 0;
        
        for (int i = 1; i < nums.length; i += 2) {
            Arrays.fill(res, cur, cur + nums[i - 1], nums[i]);
            cur += nums[i - 1];
        }
        
        return res;
    }
}