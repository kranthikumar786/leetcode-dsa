class Solution {
    public int subarraySum(int[] nums, int k) {
      int n = nums.length;
      HashMap<Integer,Integer>freMap = new HashMap<>();
      int cnt = 0 ;
      freMap.put(0,1);
      int prefixSum = 0;
      for(int i = 0 ; i < n ;i++) {
         prefixSum += nums[i];
        if(freMap.containsKey(prefixSum-k)) {
            cnt += freMap.get(prefixSum-k); 
        }
       freMap.put(prefixSum, freMap.getOrDefault(prefixSum ,0) +1); 
      }
    return cnt;
    }
}