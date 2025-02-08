class Solution {
    public int maxJump(int[] stones) {
        int res = stones[1] - stones[0], n = stones.length;
        for(int i = 2; i < n; ++i)
            res = Math.max(res, stones[i] - stones[i - 2]);
        return res;    
    }
}