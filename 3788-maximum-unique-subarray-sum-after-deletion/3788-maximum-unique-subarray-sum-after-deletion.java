class Solution {
    public int maxSum(int[] nums) {
        Set<Integer> uniquePositives = new HashSet<>();
        for (int num : nums) {
            if (num > 0) {
                uniquePositives.add(num);
            }
        }
        if (uniquePositives.isEmpty()) {
            return Arrays.stream(nums).max().orElse(Integer.MIN_VALUE);
        }
        return uniquePositives.stream().mapToInt(Integer::intValue).sum();
    }
}
