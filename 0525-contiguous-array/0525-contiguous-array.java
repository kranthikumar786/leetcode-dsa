class Solution {
    public int findMaxLength(int[] nums) {
     HashMap<Integer,Integer>hm = new HashMap<>();
     int sum  = 0;
     int ans = 0 ;
     hm.put(0,-1);
     for(int i = 0 ; i <  nums.length; i++){
           sum += nums[i] == 1 ? 1 : -1;
          if(hm.containsKey(sum)){
            ans = Math.max(ans,i-hm.get(sum));
          }  
         hm.putIfAbsent(sum,i); 
     }
     return ans;
    }
}