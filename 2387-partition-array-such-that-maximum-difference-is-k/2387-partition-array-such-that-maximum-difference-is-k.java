public class Solution {
  public int partitionArray(int[] nums, int k) {
    TreeSet<Integer> set = new TreeSet<>();
    for (int val : nums) {
      set.add(val);
    }

    int groupCount = 0;
    int currentRangeEnd = -1;

    for (int val : set) {
      if (val > currentRangeEnd) {
        currentRangeEnd = val + k;
        groupCount++;
      }
    }

    return groupCount;
  }
}
