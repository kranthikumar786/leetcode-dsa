class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long prefix = 0;
        long[] minPrefix = new long[k];
        Arrays.fill(minPrefix, Long.MAX_VALUE);
        minPrefix[0] = 0;
        long maxSum = Long.MIN_VALUE;

        for (int j = 0; j < n; j++) {
            prefix += nums[j];
            int r = (j + 1) % k;
            if (minPrefix[r] != Long.MAX_VALUE) {
                long cand = prefix - minPrefix[r];
                maxSum = Math.max(maxSum, cand);
            }
            minPrefix[r] = Math.min(minPrefix[r], prefix);
        }

        return maxSum;
    }
}

