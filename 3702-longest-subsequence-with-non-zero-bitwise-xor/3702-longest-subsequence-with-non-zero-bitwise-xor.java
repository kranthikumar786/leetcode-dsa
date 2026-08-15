class Solution {
    public int longestSubsequence(int[] nums) {
        int xor = 0;
        boolean any_not_0 = false;
        int n = nums.length;

        for (int x : nums) {
            if (!any_not_0 && x != 0) {
                any_not_0 = true;
            }
            xor ^= x;
        }

        if (xor != 0) {
            return n;
        }

        return any_not_0 ? n - 1 : 0;
    }
}